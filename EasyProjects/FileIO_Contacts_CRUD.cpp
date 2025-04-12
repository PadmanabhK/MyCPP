// You should create a Contacts.txt file in same folder, and place line mentioned below at top
// Name     |     Number

#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <ios>
#include <vector>

using namespace std;

class Contact{
    private:
        string name;
        string number;

    public:
        Contact(string Name, string Number){
            this->name = Name;
            this->number = Number;
        }

        string getName(){
            return this->name;
        }
        string getNumber(){
            return this->number;
        }

        void setName(string newName){
            this->name = newName;
        }

        void setNumber(string newNumber){
            this->number = newNumber;
        }
};

void writeFile(vector<Contact> &contacts){
    ofstream contact_reference("Contacts.txt", std::ios::trunc);
    for (Contact contact : contacts) {
        contact_reference << "     " << contact.getName() << "     |     " << contact.getNumber() << "     \n";
    }
    contact_reference.close();
}

void readFile(){
    string word = "";
    ifstream contact_reference("Contacts.txt");
    cout << endl;
    cout << "     Name     |     Number     \n";
    cout << "*******************************\n";
    while (getline(contact_reference, word)) {
        cout << word << endl;
    }
    contact_reference.close();
}

void AddContact(vector<Contact> &book){
    string name = "";
    string number = "";
    cout << "Enter a name: ";
    cin >> name;
    cout << "Enter a number: ";
    cin >> number;

    cout << name << " Was added to Contact List successfully!\n";
    book.push_back(Contact(name, number));
    writeFile(book);
}


int wordEqualizer(vector<Contact> &book, string name, int mode){
    string newName = "";
    string newNumber = "";
    int index = 0;
    for (Contact contact : book) {
        if (name == contact.getName()) {
            if (mode == 1) {
                cout << "Enter New Name: ";
                cin >> newName;
                cout << "Enter New Number: ";
                cin >> newNumber;
                book.at(index).setName(newName);
                book.at(index).setNumber(newNumber);
                cout << name << " Was changed to "<< newName <<" in Contact List successfully!\n";
            }
            else{
                book.erase(book.begin() + index);
                cout << name << " Was deleted from Contact List successfully!\n";
            }
            return 1;
        }
        index += 1;
    }
    return 0;
}

void Edit_Delete_Conditionals(vector<Contact> &book, int found, string name, string message){
    if (found == 1) {
        writeFile(book);
    }
    else{
        cout << name << message;
        return;
    }
}

void Edit_Delete_Contact(vector<Contact> &book, int mode){
    string name = "";
    cout << "Enter a name: ";
    cin >> name;
    int found = wordEqualizer(book, name, mode);
    Edit_Delete_Conditionals(book, found, name,  "Wasn't found in Contact List!\n");
}

void populateVector(vector<Contact> &book){
    if (book.size() == 0) return;
    string word = "";
    string name = "";
    string number = "";
    string numberArr = "1234567890";
    ifstream contact_reference("Contacts.txt");
    while (getline(contact_reference, word)) {
        name = "";
        number = "";
        for (int i = 0; i<word.length(); i++) {
            if(word[i] == ' ' || word[i] == '|'){
                continue;
            }
            else if(numberArr.find(word[i]) != -1){
                number += word[i];
            }
            else{
                name += word[i];
            }
        }
        book.push_back(Contact(name, number));
    }
    contact_reference.close();
}

void printMenu(){
    cout << "\n***** CONTACT BOOK ******\n";
    cout << "1 - Read Contact List\n2 - Add New Contact\n3 - Edit A Contact\n4 - Delete A Contact\n5 - Exit\n";
}

int main(){
    int choice = 0;
    vector<Contact> contacts = {};
    populateVector(contacts);
    while (true) {
        printMenu();
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                readFile();
                break;
            case 2:
                AddContact(contacts);
                break;
            case 3:
                Edit_Delete_Contact(contacts, 1);
                break;
            case 4:
                Edit_Delete_Contact(contacts, 0);
                break;
            default:
                return 0;
        }
    }
    return 0;
}
