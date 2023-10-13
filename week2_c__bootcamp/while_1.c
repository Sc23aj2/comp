#include <stdio.h>

int main () {

    char a = 1;

    while (a <= 5) {
        printf("a = %d\n", a);
        a += 2;
    }
    printf("After existing the loop: a = %d\n", a);
}
