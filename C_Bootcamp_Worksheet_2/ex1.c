#include <stdio.h>

int main () {
    int n = 5;
    int array[n];
    int i;
    int sum = 0;
    for (i = 0; i < n; i +=1){
        array[i] = i + 1;
        printf("%d\n", array[i]); 
    }
    for (i = 0; i < n; i += 1){
        sum += array[i];
    }
    printf("sum = %d\n", sum);
}