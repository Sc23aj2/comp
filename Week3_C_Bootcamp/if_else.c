#include <stdio.h>

int main () {
    float marks;
    printf("What is the marks?");
    scanf("%f", &marks);

    if (marks >= 0 && marks <= 100){
        if (marks >= 40){
       printf("You pass.\n");
    }
        else{
        printf("You fail.\n");
        }
    }
    else{
        printf("Marks is not valid.\n");
    }
}
