// Analyzes numbers of vowels, consonants, number of words, number of symbols and others
// I haven't refactored the code.

#include <cstdio>
#include <iostream>

using namespace std;

int checker(string arr, string sym, string num, char character){
    int value = arr.find(character);
    int symValue = sym.find(character);
    int numValue = num.find(character);
    if (value != -1) {
        return 1;
    }
    else if (symValue != -1) {
        return 2;
    }
    else if (character == ' ') {
        return 3;
    }
    else if (numValue != -1){
        return 4;
    }
    return 5;
}

void printStats(string word, int value){
    cout << word << " - " << value << endl;
}

int main(){
    string temp = "";
    string word = "";
    int vowels = 0;
    int consonants = 0;
    int words = 0;
    int symbols = 0;
    int emptyspace = 0;
    int numbers = 0;
    string longestWord = " ";
    string smolestWord = " ";
    string vowelWord = "aAeEiIoOuU";
    string symbolsWord = "\!@#$%^&*()_-+={}[]|;:',<>.?/";
    string numberWord= "1234567890";
    cout << "Enter a word: ";
    getline(cin, word);
    word += " ";
    for (char character : word){
        temp += character;
        switch ((checker(vowelWord, symbolsWord, numberWord, character))) {
            case 1:
                vowels += 1;
                break;
            case 2:
                symbols += 1;
                break;
            case 3:
                emptyspace += 1;
                if (temp.length() > longestWord.length()) {
                    longestWord = temp;
                }
                temp = "";
                break;
            case 4:
                numbers += 1;
                break;
            default:
                consonants += 1;
                break;
        }
    }
    temp = "";
    smolestWord = longestWord + " ";
    for (char character : word) {
        temp += character;
        if (checker(vowelWord, symbolsWord, numberWord, character) == 3) {
            if (temp.length() <= smolestWord.length()) {
                smolestWord = temp;
                temp = "";
            }
        }
    }
    cout << "***** Summary *****\n";
    cout << "---------------------\n";
    printStats("Vowels", vowels);
    printStats("Symbols", symbols);
    printStats("Empty Space", emptyspace);
    printStats("Consonants", consonants);
    printStats("Words", emptyspace + 1);
    printStats("Numbers", numbers);
    cout << "Longest Word - " << longestWord << endl;
    cout << "Smolest Word - " << smolestWord << endl;
    return 0;
}
