#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

// Define an appropriate struct
#include <stdio.h>

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

    // file_to_struct(line_buffer, buffer_size, )
    //     while (fgets(line_buffer, buffer_size, fitness_data)) {
    //     tokeniseRecord(line_buffer, ",", date, time, steps);
    //     strcpy(fitness_struct[i].date, date);
    //     strcpy(fitness_struct[i].time, time);
    //     fitness_struct[i].steps = atoi(steps);

    //     i += 1;}
}

#endif // FITNESS_DATA_STRUCT_H