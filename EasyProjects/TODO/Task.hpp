#include <string>
using namespace std;

class Task{
    private:
        string task;
        bool isCompleted = false;
    public:
        Task(string word){
            this->task = word;
        }
        string getTask(){return this->task;}
        bool getIsCompleted(){return this->isCompleted;}
        void setTask(string newTask){this->task = newTask;}
        void setIsCompleted(bool done){this->isCompleted = done;}
};
