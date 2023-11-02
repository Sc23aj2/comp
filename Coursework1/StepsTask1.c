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
    int n = 5;
    FITNESS_DATA fitness_array[59] = {};

    int i;
    int buffer_size = 100;
    char line_buffer[buffer_size];

    while (fgets(line_buffer, buffer_size, fitness_data)) {
        for (i = 0; i < 59; i += 1){
        sscanf(line_buffer, "%s", fitness_array[i].date);
        sscanf(line_buffer, "%s", fitness_array[i].time);
        sscanf(line_buffer, "%d", &fitness_array[i].steps);
        }
    }

    for (i = 0; i < 59; i += 1){
        printf("%s\n", fitness_array[i].date);
    }
    

}