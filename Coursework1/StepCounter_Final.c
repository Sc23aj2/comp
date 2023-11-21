#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
    char choice;
    int buffer_size = 100;
    FITNESS_DATA fitness_struct[100];
    
   


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
    while(1){
    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported\n");  
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    printf("Enter choice: ");

    choice = getchar();

    while (getchar() != '\n');

        char line[buffer_size];
        char fitness[buffer_size];

        char date[11];
        char time[6];
        char steps[10];
        int i = 0;
        char line_buffer_2[buffer_size];


    switch(choice){
        
    case 'A':
    case 'a':
        printf("Input filename: \n");

        fgets(line, buffer_size, stdin);
        sscanf(line, "%s", fitness);

        FILE *fitness_data = open_file(fitness, "r");
        
        break;

    case 'B':
    case 'b':
     while (fgets(line_buffer_2, buffer_size, fitness_data)) {
        tokeniseRecord(line_buffer_2, ",", date, time, steps);
        strcpy(fitness_struct[i].date, date);
        strcpy(fitness_struct[i].time, time);
        fitness_struct[i].steps = atoi(steps);

        i += 1;}

        printf("Total records: %d\n", i);
        
        break;
    }
    }    




   
   
  

   
   
    // int a;

    // for (a = 0; a < 3; a += 1){
    //     printf("%s/%s/%d\n",  fitness_struct[a].date, fitness_struct[a].time, fitness_struct[a].steps);
    // }
}