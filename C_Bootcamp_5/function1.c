#include <stdio.h>
 


int main () {
    char *filename = "data.txt";
   FILE *file = fopen(filename, r);

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    // }
    // int max_numbers = 10, i;
    // for (i = 1; i <= max_numbers; i+=1){
    //     fprintf(file, "%d\n", i*i);
    // }
    int buffer_size = 100;
    char buffer[buffer_size];

    while (fgets(buffer, buffer_size, file)) {
        printf("%s", buffer);
    }
    fclose(file);
    return 0;
}