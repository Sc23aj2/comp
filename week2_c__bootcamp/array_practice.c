#include <stdio.h>

int main () {
    char array[5]  = "Hello";
    int i;
    for (i = 5; i >= 0 ; i -= 1) {
        printf("%c\n", array[i]);
    }
    }