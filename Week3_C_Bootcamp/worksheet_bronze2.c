#include <stdio.h>

int main () {
    int number;
    printf("What is the number?\n");
    scanf("%d", &number);

    if (number%4 == 0 && number%5 == 0){
        printf("It's divisible.\n");
    }
    else{
        printf("Not divisible.\n");
    }
}