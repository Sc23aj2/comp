#include <stdio.h>

int main () {
    float radius;
    printf("Insert the radius of the circle\n");
    scanf("%f", &radius);
    float area = (22/7)*radius*radius;
    printf("area = %f\n", area);
}