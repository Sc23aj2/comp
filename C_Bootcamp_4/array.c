#include <stdio.h>

int main ()
{
    int array[5] = {1, 2, 3, 4, 5};

    int i;
    int array_n[5] = {1, 1, 1, 1, 1};

    for (i=0; i < 5; i += 1){
        array_n[i] = array[4 -i];
        printf("%d\n", array_n[i]);
    }
}