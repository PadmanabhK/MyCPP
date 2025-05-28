// 11. Student Management System (Add, Delete, Update student records)
#include <iostream>
#include <string>
#include <vector>
#include <rapidjson/document.h>
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include <fstream>

using namespace std;
using namespace rapidjson;

class Student{
    private:
        string s_name, course, grade;
        int s_id, age;
    public:
        Student(string s_name, string course, string grade, int s_id, int age){
            this->s_name = s_name;
            this->course = course;
            this->grade = grade;
            this->s_id = s_id;
            this->age = age;
        }
        void setStudent(string key){
            if (key == "name") cin >> this->s_name;
            if (key == "id") cin >> this->s_id;
            if (key == "course") cin >> this->course;
            if(key == "grade") cin >> this->grade;
            if(key == "age") cin >> this->age;
        }

        string getStudentString(string key){
            if (key == "name") return this->s_name;
            if (key == "course") return this->course;
            if(key == "grade") return this->grade;
            return "";
        }

        int getStudentInt(string key){
            return (key == "id") ? this->s_id : this->age;
        }

        void getStudentInfo(){
            cout << "***** STUDENT INFO *****\n";
            cout << "Name: " << this->s_name << "\nId: "
            << this->s_id << "\nCourse: " << this->course << "\nAge: "
            << this->age << "\nGrade: " << this->grade << "\n";
            cout << "************************\n";
        }
};

void menu(){
    cout << "1 - Add Student\n2 - Remove Student\n3 - Update Student\n4 - GetStudentInfo\n5 - All Students\n";
}

void writeFile(vector<Student> studentList){
    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);

    writer.StartArray(); // Start of main JSON array
    for (Student student : studentList) {
        writer.StartObject(); // Start of a student object

        writer.Key("name");
        writer.String(student.getStudentString("name").c_str());

        writer.Key("id");
        writer.Int(student.getStudentInt("id"));

        writer.Key("grade");
        writer.String(student.getStudentString("grade").c_str());

        writer.Key("course");
        writer.String(student.getStudentString("course").c_str());

        writer.Key("age");
        writer.Int(student.getStudentInt("age"));

        writer.EndObject(); // End of a student object
    }
    writer.EndArray(); // End of main JSON array
    ofstream ofs("StudentRecords.json");
    ofs << buffer.GetString();  // Writes formatted JSON to file
    ofs.close();
    return;
}

void addDetails(string *name, string *course, string *grade, int *id, int *age){
    cout << "Enter Student name: ";
    cin >> *name;
    cout << "Enter Course: ";
    cin >> *course;
    cout << "Enter grade: ";
    cin >> *grade;
    cout << "Enter Student id: ";
    cin >> *id;
    cout << "Enter your age: ";
    cin >> *age;
}

void ModifyAccount(Student *s){
    string choice;
    string word;
    cout << "Details you wanna change? specify each with a comma in between: ";
    cout << "For ex: name,age,grade,id,course\n";
    cin >> choice;
    choice += ',';
    for (char w: choice) {
        if (w == ',') {
            cout << "Enter new " << word << ": ";
            s->setStudent(word);
            word = "";
        }
        else{
            word += w;
        }
    }
    cout << "Student Updated Successfully!!!\n\n";
}

void iterate(int id, vector<Student> &list, int choice){
    int it = 0;
    cout << "Enter Student ID: ";
    cin >> id;
    for (Student &s : list) {
        if (s.getStudentInt("id") == id) {
            if (choice == 2) {
                cout << "Student: " << s.getStudentString("name") << " with ID: " << s.getStudentInt("id") << " Has been removed!!!\n";
                list.erase(list.begin() + it);
                break;
            }
            choice == 3 ? ModifyAccount(&s) : s.getStudentInfo();
        }
        it++;
    }
    writeFile(list);
}

int main(){
    vector<Student> StudentList;
    int choice, id, age;
    string name, course, grade;
    string word;

    ifstream StudentFile("StudentRecords.json");
    string json((istreambuf_iterator<char>(StudentFile)), istreambuf_iterator<char>());
    Document doc;
    doc.Parse(json.c_str());
    if (doc.HasParseError()) {
        cerr << "Error parsing JSON: "
             << doc.GetParseError() << endl;
        return 1;
    }
    else{
        for (int i=0; i<doc.Size(); i++) {
            StudentList.push_back(Student(doc[i]["name"].GetString(), doc[i]["course"].GetString(),
                doc[i]["grade"].GetString(), doc[i]["id"].GetInt(), doc[i]["age"].GetInt()));
        }
        StudentFile.close();
    }
    while (true) {
        menu();
        cout << "Enter your choice: \n";
        cin >> choice;
        switch (choice) {
            case 1:
                addDetails(&name, &course, &grade, &id, &age);
                StudentList.push_back(Student(name, course, grade, id, age));
                writeFile(StudentList);
                cout << "Student Added Successfully\n";
                break;
            case 2:
            case 3:
            case 4:
                iterate(id, StudentList, choice);
                break;
            case 5:
                cout << "***** ALL STUDENTS ******\n";
                for (Student s : StudentList) {
                    cout << "-----------------------" << endl;
                    s.getStudentInfo();
                    cout << "-----------------------" << endl;
                }
                cout << "************************\n";
                break;
            default:
                return 0;
        }
    }
    return 0;
}
