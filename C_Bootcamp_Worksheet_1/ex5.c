#include <stdio.h>

int main () {
    int var1 = 3;
    int var2 = 4;
    printf("var1 = %d, var2 = %d\n", var1, var2);
    int var = var1;
    var1  = var2;
    var2 = var;
    printf("var1 = %d, var2 = %d\n", var1, var2);

}