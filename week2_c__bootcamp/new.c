#include <stdio.h>

int main () {
    int a = 1;

    for (;a < 11;) {
        printf("%d\n", a*a);
        a += 1;
    }
    return 0;
}