// You need RapidJson library installed on your machine 

#include <iostream>
#include <rapidjson/document.h>
#include <fstream>
#include <string>

using namespace std;
using namespace rapidjson;

int main(){
    int choice, score;
    ifstream questions("quiz_questions_30.json");
    cout << "Hello World\n";


    string json((istreambuf_iterator<char>(questions)),
                   istreambuf_iterator<char>());

       // Create a Document object
         // to hold the JSON data
    Document doc;

    // Parse the JSON data
    doc.Parse(json.c_str());

    // Check for parse errors
    if (doc.HasParseError()) {
       cerr << "Error parsing JSON: "
            << doc.GetParseError() << endl;
       return 1;
    }

    for (int i=0; i<30; i++) {
        cout << doc[i]["question"].GetString() << endl;
        for (int j=0; j<4; j++){
            cout << j + 1 << ") " << doc[i]["options"][j].GetString() << endl;
        }
        cout << "Enter your Answer: ";
        cin >> choice;
        if ((string)doc[i]["options"][choice - 1].GetString() == (string)doc[i]["answer"].GetString()) {
            cout << "You Guessed Correct!!!" << endl;
            score++;
        }
        cout << "-------------------------------------" << endl;
    }
    cout << "Your Total Score: " << score << " out of 30" << endl;
    questions.close();
	return 0;
}
