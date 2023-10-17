#include <stdio.h>

int main() {
    int array_1[3] = {1, 2, 3};
    int array_2[3] = {4, 5, 6};
    int n = 6;
    int array[n];
    int i;
    for (i=0; i < 3; i +=1){
        array[i] = array_1[i];
        array[i + 3] = array_2[i];
    }
    //int size = sizeof(array);
    //printf("%d\n", size);
    for (i=0; i < n; i += 1){
        printf("%d\n", array[i]);
    }
}