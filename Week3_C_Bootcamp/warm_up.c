#include <stdio.h>

int main () {
    float temperature;
    printf("What is the temperature today?");
    scanf("%f", &temperature);

    if (temperature > 20){
       printf("No need for a jacket.\n");
    }
    else if (temperature > 10)
        printf("Wear a light jacket\n");
    else
        printf("Wear a jacket.\n");

    }
