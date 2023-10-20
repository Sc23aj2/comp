#include <stdio.h>

float sum(float a, float b)
{
    float answer;
    answer = a + b;
    return answer;
}

int main()
{
    float y = 2.5;
    float z = sum(3, y);
    printf("the sum of 3 and %.2f is %.2f.\n", y, z);
}