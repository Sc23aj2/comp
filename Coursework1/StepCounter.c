#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
    int true = 1;
    while(true == 1){    
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
        char filename[buffer_size];

        char date[11];
        char time[6];
        char steps[10];
        char line_buffer_2[buffer_size];


    switch(choice){
        
    case 'A':
    case 'a':
        
        printf("Input filename: ");
        fgets(line, buffer_size, stdin);
        sscanf(line, " %s ", filename);

        FILE *fitness_data = open_file(filename, "r");

        int i = 0;
        while (fgets(line_buffer_2, buffer_size, fitness_data)) {
        tokeniseRecord(line_buffer_2, ",", date, time, steps);
        strcpy(fitness_struct[i].date, date);
        strcpy(fitness_struct[i].time, time);
        fitness_struct[i].steps = atoi(steps);

        i += 1;}
     
        break;

    case 'B':
    case 'b':
    if(fitness_data != NULL){
        printf("Total records: %d\n", i);
    }
    else{
        printf("Please specify a filename first.\n");
    }
        break;

    case 'C':
    case 'c':
        if(fitness_data != NULL){
            int least_steps = fitness_struct[0].steps;
            int z;
            for(int b = 0; b < i; b += 1){
                if (fitness_struct[b].steps < least_steps){
                    least_steps = fitness_struct[b].steps;
                    z = b;
                }
            }
            printf("Fewest steps: %s %s\n", fitness_struct[z].date, fitness_struct[z].time);

        }

         else{
        printf("Please specify a filename first.\n");
    }
        break;

    case 'D':
    case 'd':
         if(fitness_data != NULL){
            int most_steps = fitness_struct[0].steps;
            int d;
            for(int e = 0; e < i; e += 1){
                if (fitness_struct[e].steps > most_steps){
                    most_steps = fitness_struct[e].steps;
                    d = e;
                }
            }
            printf("Largest steps: %s %s\n", fitness_struct[d].date, fitness_struct[d].time);


        }

         else{
        printf("Please specify a filename first.\n");
    }
        break;

    case 'E':
    case 'e':
         if(fitness_data != NULL){
            float mean = 0;
            for (int a = 0; a < i; a += 1){
                mean += fitness_struct[a].steps;
            }
            mean /= i;
            int rounded_mean = round(mean);
            printf("Mean step count: %d\n", rounded_mean);
    

        }

         else{
        printf("Please specify a filename first.\n");
    }
        break;

    case 'F':
    case 'f':
         if(fitness_data != NULL){
            int y = 0;
            int continuous = 0;
            int end;
            int start;
            for(int h = 0; h < i; h += 1){
                if(fitness_struct[h].steps > 500){
                    y += 1;
                    if(continuous < y){
                        continuous = y;
                        end = h;                 
                    }
                }
                else{
                    y = 0;
                }
            }
            start = end - continuous + 1;
            printf("Longest period start: %s %s\nLongest period end: %s %s\n",fitness_struct[start].date, fitness_struct[start].time, fitness_struct[end].date, fitness_struct[end].time);

        }

         else{
        printf("Please specify a filename first.\n");
    }
        break;        
        
    case 'Q':
    case 'q':
        fclose(fitness_data);
        true = 0;
        return 0;   

    default :
        printf("Invalid choice. Try again.\n");
        break;    
    }
   
    }    
}