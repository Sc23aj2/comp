#include <stdio.h>

int main () {

    int a;

    for (a = 1; a <= 5; a += 1) {
        printf("a = %d\n", a);
    }
    printf("After existing the loop: a = %d\n", a);
}
