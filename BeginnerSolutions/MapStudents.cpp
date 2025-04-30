// Taking Student's name and age and storing it in a map
#include <iostream>
#include <map>

using namespace std;

int main() {
	int num, tempAge;
	string tempName;

	map<string, int> students;

	cout << "Enter number of students: ";
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cout << "Enter " << i + 1 << "st student's name: \n";
		cin >> tempName;

		cout << "Enter age: ";
		cin >> tempAge;

		students[tempName] = tempAge;
	}

	map<string, int> ::iterator studentList;

	for (studentList = students.begin(); studentList != students.end(); ++studentList)
	{
		cout << studentList->first << " - " << studentList->second << "\n";
	}
	return 0;
}
