#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

// Define an appropriate struct
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

FILE *open_file(char *filename, char *mode){
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        printf("Error: Could not find or open the file.\n");
        exit(1);
    }
    else{
    printf("File successfully loaded.\n");    
    return file;
    }
}

#endif // FITNESS_DATA_STRUCT_H