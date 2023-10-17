#include <stdio.h>

int main () {
    int mark;
    printf("What is the mark?");
    scanf("%d", &mark);

    if (mark >= 0 && mark <= 100){
        if (mark >= 70){
            printf("Distinction\n");
        }
        else if (mark >=50){
            printf("Passed\n");
        }
        else{
            printf("Failed\n");
        }
    }
}