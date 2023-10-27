#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char mark_t;

typedef struct  {
    char name [20];
    char student_id [10];
    mark_t mark;
} student;

int main () {
    // struct student new_student = {.name = "Name Surname", .student_id = "201720408", .mark = 35};
    student new_student = {.mark = 33};
    // printf("Insert data [name, student_id, mark]");
    // scanf("%s", new_student.name);
    // scanf("%s", new_student.student_id); 
    // scanf("%d", &new_student.mark);

    strcpy(new_student.name, "Name Surname");
    strcpy(new_student.student_id, "201720408");
    // new_student.mark = 33;

    char mark_1[] = "33";
    new_student.mark = atoi(mark_1);

    printf("Student name: %s\n", new_student.name);
    printf("Student ID: %s\n", new_student.student_id);
    printf("Mark: %u\n", new_student.mark);
    return 0;
}