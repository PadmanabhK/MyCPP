#include <iostream>
#include <set>

using namespace std;
// Taking Inputs and storing unique values in a set
int main() {
    set<int> nums;
    int num, temp;

    cout << "Enter number of elements to sort: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "Enter " << i+1 << "st element: ";
        cin >> temp;
        nums.insert(nums.begin(), temp);
    }

    for (int n : nums) {
        cout << n << "\n";
    }
    return 0;
}
