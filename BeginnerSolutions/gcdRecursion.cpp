// Greatest Common Divisor using recursion
// I haven't used any algorithm - just tried to find gcd
// Code might throw error - even though I haven't found any
#include <iostream>

using namespace std;

int gcdFinder(int gcd, int count, int limit, int a, int b) {
    return (count <= limit) ? ((a % count == 0 && b % count == 0) ? gcdFinder(gcd * count, count + 1, limit, a, b) : gcdFinder(gcd, count + 1, limit, a, b)) : gcd;
}

int main() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    int limit = ((a < b) ? a : b);

    cout << "GCD of " << a << " and " << b << " is " << gcdFinder(1, 2, limit, a, b);

    return 0;
}
