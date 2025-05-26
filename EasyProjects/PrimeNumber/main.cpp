#include <stdio.h>

void PrimePrinter(int num, bool isPrime){
    printf("%s", "*****************************\n1\n");
    for (int i=2; i<num; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) printf("%d\n", i);
        isPrime = true;
    }
    printf("%s", "********************************\n");
}

void primeChecker(int num){
    for (int i=2; i<num; i++) {
        if (num % i == 0) {printf("%s", "Not a Prime Number\n"); return;}
    }
    printf("%s\n", "A Prime Number");
}

int main(){
    int num;
    bool isPrime = true;
    int generatePrime = 0;
    printf("%s", "1 - Generate Prime Numbers, \n0 - check whether a number is prime number\n");
    scanf("%d", &generatePrime);
    printf("%s", "Enter number: ");
    scanf("%d", &num);
    (generatePrime) ? PrimePrinter(num, isPrime) : primeChecker(num);
    return 0;
}
