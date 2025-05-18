#include <stdint.h>
#include <stdio.h>
#include "func.h"

void menu(){
    printf("%s", "***** Options *****\n1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - exit\n");
}

float operations(float num1, float num2, int op){
    switch (op) {
        case 1: return (num1 + num2);
        case 2: return (num1 - num2);
        case 3: return (num1 * num2);
        case 4: if (num2 == 0) {
            printf("%s", "Division by Zero Error!!!\n");
            return (float)(intptr_t)NULL;
        } return num1 / num2;
    }
    return 0;
}
