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
    int n = 10;
    student new_students [n];
    //      {"Alice Smith",    "64827593", 67},
    //     {"Bob Johnson",    "19374650", 89},
    //     {"Charlie Brown",  "82056914", 76},
    //     {"David Davis",    "45790182", 44},
    //     {"Eve Wilson",     "36102478", 91},
    //     {"Frank Anderson", "93571826", 53},
    //     {"Grace Lee",      "50249867", 78},
    //     {"Hannah Clark",   "74820591", 62},
    //     {"Isaac Harris",   "61093745", 89},
    //     {"Jack White",     "92847501", 72}
    // };

    int i;
    for (i = 0; i < n; i +=1){
        sprintf(new_students[i].name, "Student %d", i);
        sprintf(new_students[i].student_id, "20171040%d", i);
        new_students[i].mark = 35 + (13 +(17 * i)) % 65;
    }
    
    for (i = 0; i < n; i += 1){
    printf("Student name: %s\n", new_students[i].name);
    printf("Student ID: %s\n", new_students[i].student_id);
    printf("Mark: %u\n", new_students[i].mark);
    }
    return 0;
}