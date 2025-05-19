#include <iostream>
#include <vector>
#include "Task.hpp"

using namespace std;

void menu(){
    cout << "1 - Add a task\n2 - Modify a task\n3 - Task Info\n4 - All Tasks\n5 - Delete a task\n6 - exit" << endl;
}

void inputter(string prompt, int *choice, string *task){
    if(*choice == 1){
        cout << prompt;
        cin >> *task;
    }
    if (*choice == 2) {
        cout << "Enter the index of task: ";
        cin >> *choice;
        cout << prompt;
        cin >> *task;
    }
    else if(*choice == 4){
        return;
    }
    else{
        cout << "Enter the index of task: ";
        cin >> *choice;
    }
}

int main(){
    string prompts[] = {"Enter a task: ", "Enter a new taskname to replace: ", "Enter the index of task: ", "", "Enter the index of task: "};
    int choice;
    string taskName;
    bool isCompleted;
    vector<Task> tasks;
    while (true) {
        menu();
        cout << "Enter Your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 5) {return 0;}
        inputter(prompts[choice - 1], &choice, &taskName);
        switch (choice) {
            case 1:
                tasks.push_back(Task(taskName));
                cout << "Task Added successfully\n" << endl;
                break;
            case 2:
                tasks.at(choice).setTask(taskName);
                cout << "Task Replaced successfully\n" << endl;
                break;
            case 3:
                cout << choice << " | " << tasks.at(choice).getTask() << " | " << tasks.at(choice).getIsCompleted() << endl;
                break;
            case 4:
                cout << "***************** TASKS ************************\n";
                choice = 0;
                for (Task task : tasks) {
                    cout << ++choice << " | " << task.getTask() << " | " << task.getIsCompleted() << endl;
                }
                cout << "************************************************\n";
                break;
            case 5:
                tasks.erase(tasks.begin() + choice - 1);
                cout << "Task Removed successfully\n" << endl;
                break;
        }
    }
    return 0;
}
