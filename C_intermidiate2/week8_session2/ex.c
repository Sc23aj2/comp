
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 5
#define COLS 2

typedef struct{
    char date[11];
    float bloodiron;
} Bloodiron;

// Function to tokenize a string
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *bloodiron) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(bloodiron, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

int main(){

    Bloodiron bloodiron_struct[2] = {};
    FILE *file = fopen("data.txt", "r");

    if (file == NULL){
        printf("Error opening the file.\n");
        return 1;
    }

    char line[100];
    
    

    char date[11];
    char bloodiron[3];
    int i = 0;

    while(fgets(line, sizeof(line), file)){
    tokeniseRecord(line, ",", date, bloodiron);

    bloodiron_struct[i].date = date;
    bloodiron_struct[i].bloodiron = atof(bloodiron);

    i += 1;
    }

    fclose(file);
}