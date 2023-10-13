#include <stdio.h>

int main () {
    int N = 10;
    int array [N];
    int i;
    for (i = 0; i < N ; i += 1) {
        array[i] = i;
    }

    for (i = 0; i < N; i += 1) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    }