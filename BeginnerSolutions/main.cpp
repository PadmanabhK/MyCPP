#include <iostream>

using namespace std;

int main()
{
    //// Hello World
    //cout << "Hello World\n";

    //// Even Or Odd
    //int num;
    //cout << "Enter a Number: ";
    //cin >> num;
    //cout << num << " is " << (num % 2 == 0 ? "Even" : "Odd");

    //// Largest Of three
    //int a, b, c;
    //cout << "Enter three numbers : ";
    //cin >> a >> b >> c;
    //cout << (a > b && a > c ? a : (b > a && b > c ? b : c)) << " is greater";

    // Loops and Iteration

    //// Sum of First N numbers
    //int num;
    //int temp = 0;
    //cout << "Enter A number: ";
    //cin >> num;
    //while (num > 0) {
    //    temp += num;
    //    num -= 1;
    //}
    //cout << "Sum is: " << temp;

    //// Factorial
    //int num;
    //int fact = 1;
    //cout << "Enter A Number: ";
    //cin >> num;
    //if (num == 0 || num == 1) {
    //    cout << "Factorial is 1";
    //}
    //else {
    //    while (num > 1) {
    //        fact *= num;
    //        num -= 1;
    //    }
    //    cout << "Factorial is: " << fact;
    //}


    //// Multiplication Table
    //int table = 0;
    //cout << "Enter Table Number: ";
    //cin >> table;

    //for (int i = 1; i < 11; i++)
    //{
    //    cout << table << " X " << i << " = " << table * i << "\n";
    //}


    //// Reverse A Number
    //int num;
    //cout << "Enter A Number: ";
    //cin >> num;

    //while (num > 0) {
    //    //cout << num << "\n";
    //    cout << num % 10;
    //    num /= 10;
    //}


    //// Prime Detector
    //int num;
    //bool isPrime;
    //cout << "Enter A Number: ";
    //cin >> num;

    //if (num > 3)
    //{
    //    isPrime = true;
    //    for (int i = 2; i < num; i++) {
    //        if (num % i == 0) {
    //            isPrime = false;
    //            cout << "Not a prime number";
    //            return -1;
    //        }
    //    }
    //    cout << "A prime number";
    //}


    //// Biggest Element in an Array
    //int nums[5] = {111, 6, 22, 14, 9};
    //int max = 0;
    //for (int i = 0; i < size(nums); i++)
    //{
    //    max = (nums[i] > max) ? nums[i] : max;
    //}
    //cout << max << " is the biggest element in the array";


    //// Reversing an Array
    //int nums[5] = { 1, 2, 3, 4, 5 };
    //int temp = 0;
    //for (int i = 0; i < size(nums) / 2; i++)
    //{
    //    int temp = nums[i];
    //    if (i == 0) {
    //        nums[i] = nums[size(nums) - 1];
    //        nums[size(nums) - 1] = temp;
    //    }
    //    else {
    //        nums[i] = nums[size(nums) - i - 1];
    //        nums[size(nums) - i - 1] = temp;
    //    }
    //    
    //}
    //for (int i = 0; i < size(nums); i++)
    //{
    //    cout << nums[i] << "\n";
    //}


    //// Palindrome Checker
    //string word;
    //cout << "Enter a word: ";
    //cin >> word;
    //int res = 1;
    //int i = 0;
    
    //while (res == 1 && i < size(word) / 2) {
    //    res = (word[i] == word[size(word) - i - 1] ? 1 : -1);
    //    i += 1;
    //}
    //cout << ((res == 1) ? "A Palindrome" : "Not a palindrome");
    
    
    //// Count Vowels and Consonants in a string
    //string word;
    //string vowel = "aeiouAEIOU";
    //cout << "Enter a word: ";
    //cin >> word;
    //int vowels = 0, consonants = 0;
    
    //for (int i = 0; i < size(word); i++)
    //{   
    //    (vowel.find(word[i]) < 100) ? vowels++ : consonants++;
    //}
    //cout << "Vowels: " << vowels << "\nConsonants: " << consonants;
  return 0;
}

// NOTES:
// use size() to get the length of Arrays, not sizeOf()
// Take Multiple inputes for ex: cin >> a >> b >> c; which is a pain in C;
// Haven't used format specifiers like %d, %c - so writing code in C++ is easy relatively
// Most of the syntax is identical to most of the languages
// Strings can be manipulated
// usage of const - big W, but still haven't used that many times
// Ternary operator literally saves several lines of code
// I don't know whether I should squeeze code again and again?
