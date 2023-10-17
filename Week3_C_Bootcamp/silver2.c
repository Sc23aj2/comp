#include <stdio.h>

int main () {
    float temperature;
    printf("What's the temperature?");
    scanf("%f", &temperature);

    if (-10 < temperature && temperature < 40){
        printf("It's within the range.\n");
    }
    else{
        printf("Out of range.\n");
    }
}