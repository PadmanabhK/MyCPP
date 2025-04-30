#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num, temp, min;
    vector<int> nums = {};

    cout << "Enter number of elements to sort: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "Enter " << i+1 << "st element: ";
        cin >> temp;
        nums.insert(nums.begin() + i, temp);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        min = i;
        for (int j = i+1; j < nums.size(); j++)
        {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }
    for (int n : nums) {
        cout << n << "\n";
    }
    return 0;
}
