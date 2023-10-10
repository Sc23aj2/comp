#include <stdio.h>

int main () {
    float var1;
    float var2;
    printf("Give side lengths: ");
    scanf("%f %f", &var1, &var2);
    float area;
    area = 0.5*var1*var2;
    printf("Area of a triangle = %f\n", area);
    return 0;
}