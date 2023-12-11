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

    char date[11];
    char time[6];
    int steps;
    char line_buffer_2[buffer_size];
    int i = 0;

    while (fgets(line_buffer_2, buffer_size, fitness_data)) {
        tokeniseRecord(line_buffer_2, ',', date, time, &steps);
   
        strcpy(fitness_struct[i].date, date);
        strcpy(fitness_struct[i].time, time);
        fitness_struct[i].steps = steps;

        i += 1;
    }
    fclose(fitness_data);

    for(int a = 0; a < i; a += 1){
        if(fitness_struct[a].steps == 0){
        printf("Error: invalid file\n");
        exit(1);
    }
    }

    FitnessData fitness_struct_arranged[100];
    int d;
    int z;

        for(z = 0; z < i; z += 1){
            int most_steps = 0;
            for(int e = 0; e < i; e += 1){
                if (fitness_struct[e].steps > most_steps){
                    most_steps = fitness_struct[e].steps;
                    d = e;
                }
            }
            strcpy(fitness_struct_arranged[z].date, fitness_struct[d].date);
            strcpy(fitness_struct_arranged[z].time, fitness_struct[d].time);
            fitness_struct_arranged[z].steps = most_steps;
            for(int g = d; g < i; g += 1){
                fitness_struct[g] = fitness_struct[g + 1];
            }
        }

    char tsv_file[buffer_size];    
    snprintf(tsv_file, buffer_size, "%s.tsv", filename);
    FILE *new_fitness_data = open_file(tsv_file, "w");
    for(int m = 0; m < i; m += 1){      
    fprintf(new_fitness_data,"%s\t%s\t%d\n",fitness_struct_arranged[m].date, fitness_struct_arranged[m].time, fitness_struct_arranged[m].steps);  
}

    printf("Data sorted and written to FitnessData_2023.csv.tsv\n");
    fclose(new_fitness_data);
}
