#include <cctype>
#include <fstream>
#include <string>

using namespace std;


void ENCRYPT(string character, string word, string text, string result, int index, int shift){
    ifstream random("random.txt");
    while (getline(random, character)){
       text += character;
    }
    random.close();

    for (char c : text)
    {
        if(c == ' ' || c == '.' || c == ','){
            result += c;
            continue;
        }
        index = word.find((char)tolower(c));
        if (index + shift > 25)
        {
            index = (index + shift) - 26;
            result += word[index];
            continue;
        }
        result += word[index + shift];
    }
    ofstream write("random.txt");
    write << result;
    write.close();
}


void DECRYPT(string character, string word, string text, string result, int index, int shift){
    ifstream random("random.txt");
    while (getline(random, character))
    {   text += character;

    }
    random.close();
    for (char c : text)
    {
        if(c == ' ' || c == '.' || c == ','){
            result += c;
            continue;
        }
        index = word.find((char)tolower(c));
        if (index - shift < 0) {
            result += word[26 + index - shift];
        }
        else{
            result += word[index - shift];
        }
    }
    ofstream write("random.txt");
    write << result;
    write.close();
}


int main(){
    string word = "abcdefghijklmnopqrstuvwxyz";
    string character, text, result, re_result;
    int index{0};
    int shift{8};
    ENCRYPT(character, word, text, result, index, shift);
    character = "", text = "", result = "", index = 0;
    DECRYPT(character, word, text, result, index, shift);
    return 0;
}
