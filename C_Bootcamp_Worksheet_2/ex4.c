#include <stdio.h>

int main () {
    int array[5] = {10, 9, 8, 7, 6};
    int i = 5;
    int temp = array[4];
    while (i > 0){
        array[i] = array[i - 1];
        i -= 1;
    }
    array[0] = temp;
    for (i = 0; i < 5 ; i += 1){
        printf("%d\n", array[i]);
    }
}