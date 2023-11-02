#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    char* fitness = "FitnessData_2023.csv";
    FILE *fitness_data = fopen(fitness, "r");
    if (fitness_data == NULL){
        printf("Error opening file\n");
        return 1;
    }
    
    FITNESS_DATA fitness_struct[100];

    char* sp;
    int i = 0;
    int buffer_size = 100;
    char line_buffer[buffer_size];

    while (fgets(line_buffer, buffer_size, fitness_data)) {
        sp = strtok(line_buffer, ",");
        strcpy(fitness_struct[i].date, sp);

        sp = strtok(NULL, ",");
        strcpy(fitness_struct[i].time, sp);

        sp = strtok(NULL, ",");
        fitness_struct[i].steps = atoi(sp);

        i +=1;

    }

    for (i = 0; i < 59; i +=1){
        printf("%s\n", fitness_struct[i].date);
        printf("%s\n", fitness_struct[i].time);
        printf("%d\n", fitness_struct[i].steps);
    }

}