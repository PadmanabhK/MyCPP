#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string word = "abcdefghijklmnopqrstuvwxyz";
    string character, text, result, re_result;
    int index{0};
    int shift{5};
    // ifstream random("random.txt");
    // while (getline(random, character))
    // {   text += character;
        
    // }
    // random.close();
    
    for (char c : word)
    {
        index = word.find(c);
        if (index + shift > 25)
        {
            index = (index + shift) - 26;
            // cout << c << " - EXCEEDED!!! - " << index << " - " << word[index] << endl;
            // cout << c << " - " << word[index] << endl;
            result += word[index];
            continue;
        }
        
        // cout << c << " - " << word[index + shift] << endl;
        result += word[index + shift];
    }
    
    cout << result << endl;

    return 0;
}

