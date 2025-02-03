#include <iostream>
// Fibonacci Series using recursion
using namespace std;

void printSeries(int i, int num, int op1, int op2) {
    if (i < num) {
        cout << op2 + op1 << "\n";
        printSeries(i + 1, num, op2, op2 + op1);
    }
}
int main() { 
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "0\n" << "1\n";
    printSeries(2, num, 0, 1);
    return 0;
}
