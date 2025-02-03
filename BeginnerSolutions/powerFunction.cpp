#include <iostream>
// power function using recursion
using namespace std;

int powerFunction(int value, int num, int power) {
    return (power > 0) ? powerFunction(value *= num, num, power - 1) : value;
}

int main() {
    int num, power;
    cout << "Enter the number and it's power: ";
    cin >> num >> power;
    cout << num << " to the power of " << power << " is " << powerFunction(1, num, power);
    return 0;
}
