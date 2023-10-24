#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>

FILE *file_open(char filename[], char mode[]){
     char filename[] = "./data.txt";
    FILE *file = fopen(filename, "w");
    if (file == NULL){
        perror("File I/O");
        exit (1);
    }
    return file;
}
#endif    