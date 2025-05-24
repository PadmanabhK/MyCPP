#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contact{
    private:
        string name, number;
    public:
        Contact(string name, string number){
            this->name = name;
            this->number = number;
        }
        string getName(){return this->name;}
        string getNumber(){return this->number;}
        void setName(string newName){this->name = newName;}
        void setNumber(string newNumber){this->number = newNumber;}
};

void inputter(string *name, string *number){
    cout << "Enter your name: ";
    cin >> *name;
    cout << "Enter your number: ";
    cin >> *number;
}

void writeFile(vector<Contact> &ContactList){
    ofstream write("Contacts.txt");
    for (Contact contact : ContactList) {
        write << "     " << contact.getName() << "     |     " << contact.getNumber() << endl;
    }
    write.close();
}

void addAccount(string name, string number, vector<Contact> &contactList){
    Contact *con = new Contact(name, number);
    contactList.push_back(*con);
    cout << "Contact [" << name << " - " << number << "] added successfully!\n";
    writeFile(contactList);
}

void ModAccount(string *name, string *number, vector<Contact> &contactList, int choice){
    int i = 0;
    for (Contact& contact : contactList) {
        if (*name == contact.getName() && *number == contact.getNumber()) {
            if (choice == 2) {
                cout << "Contact [" << name << " - " << number << "] removed successfully!\n";
                contactList.erase(contactList.begin() + i);
            }
            else{
                cout << "Enter new name and number: \n";
                inputter(name, number);
                contact.setName(*name);
                contact.setNumber(*number);
                cout << "Contact was Modified Successfully\n";
            }
        }
        i++;
    }
    writeFile(contactList);
}

void populateVector(vector<Contact> &ContactList){
    string word, name, number;
    string numberArr = "1234567890";
    ifstream read("Contacts.txt");
    while (getline(read, word)) {
        for (char s : word) {
            if (numberArr.find(s) != -1) {
                number += s;
            }
            else if(s == ' ' || s == '|'){
                continue;
            }
            else{
                name += s;
            }
        }
        Contact *contact = new Contact(name, number);
        ContactList.push_back(*contact);
        name = "";
        number = "";
    }
    read.close();
    writeFile(ContactList);
}

void menu(){
    cout << "1 - Add Contact\n" << "2 - Delete Contact\n" << "3 - Modify Contact\n" << "4 - Contact List\n" << "5 - Find Contact" << endl;
}

int main(){
    vector<Contact> ContactList;
    int choice = 1;
    string name, number;
    ifstream in("Contacts.txt");
    if(in.is_open())
    {
        in.seekg(0,ios::end);
        size_t size = in.tellg();
        if( size == 1)
        {
            cout << "File is empty\n";
        }
        else{
            populateVector(ContactList);
        }
    }
    in.close();
    while(true){
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                inputter(&name, &number);
                addAccount(name, number, ContactList);
                break;
            case 2:
            case 3:
                inputter(&name, &number);
                ModAccount(&name, &number, ContactList, choice);
                break;
            case 4:
                cout << "     Name     |     Number     \n*******************************\n";
                for (Contact contact : ContactList) {
                    cout << "     " << contact.getName() << "     |     "<< contact.getNumber() << endl;
                }
                break;
            default:
                return 0;
        }
    }

    return 0;
}
