#include <iostream>

using namespace std;

void menu(){
    cout << "1 - Degree Celsius to Fahrenhite\n2 - Fahrenhite to Degree\n";
}

void inputter(string prompt, float* a){
    cout << prompt;
    cin >> *a;
}

int main(){
    float choice;
    float value;
    string prompt;
    while (true) {
        menu();
        inputter("Enter your choice: ", &choice);
        if (choice == 1 || choice == 2) {
            prompt = choice == 1 ? "Enter Temperature in degrees: " : "Enter Temperature in Fahrenhite: ";
            inputter(prompt, &value);
            if (choice == 1) cout << "Temperature in Fahrenhite: " << (value * 9/5) + 32 << endl;
            else cout << "Temperature in Degree Celsius: " << (value - 32) * 5/9 << endl;
            continue;
        }
        break;
    }
    return 0;
}
