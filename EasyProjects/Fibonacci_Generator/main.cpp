#include <stdio.h>

int main(){
    int num1 = 0;
    int num2 = 1;
    int temp, choice;

    printf("%s", "Enter Your choice: ");
    scanf("%d", &choice);
    printf("%s\n", "0");
    for (int i=0; i < choice-1; i++) {
        num2 = num1 + num2;
        temp = num2;
        num2 = num1;
        num1 = temp;
        printf("%d\n", num1);
    }
    return 0;
}
