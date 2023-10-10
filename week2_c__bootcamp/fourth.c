#include <stdio.h>

int main () {
    // This is a comment.
    /*
    This is also a comment.
    */
    char name [10];
    printf("Insert a name");
    scanf("%s", name);
    printf("Hello,  %s\n", name);
    return 0;
}