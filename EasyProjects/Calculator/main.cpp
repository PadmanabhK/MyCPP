// #include <iostream>
#include <stdio.h>
#include "func.h"

int main(){
    float op1, op2;
    int choice;
    printf("%s","Enter first number: ");
    scanf("%f", &op1);
    menu();
    printf("%s", "Enter operation: ");
    scanf("%d", &choice);
    printf("%s","Enter second number: ");
    scanf("%f", &op2);

    while (true) {
        op1 = operations(op1, op2, choice);
        if (op1 == float(NULL)) { return -1; }
        printf("%s", "********************************************\n");
        printf("Answer: %.2f\n", op1);
        menu();
        printf("%s", "Enter operation: ");
        scanf("%d", &choice);
        if (choice >= 5 || choice < 0) {break;}
        printf("%s","Enter second number: ");
        scanf("%f", &op2);
        printf("%s", "********************************************\n");
    }
    return 0;
}
