#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

    int buffer_size = 100;
    FitnessData fitness_struct[100];
    

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

FILE *open_file(char *filename, char *mode){
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        printf("Error: invalid file\n");
        exit(1);
    }
    else{
    return file;
    }
}


int main() {
    char line[buffer_size];
    char filename[buffer_size];

    printf("Enter Filename: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    FILE *fitness_data = open_file(filename, "r");
}
