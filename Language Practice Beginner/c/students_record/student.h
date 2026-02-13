#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

typedef struct {
    int id;
    char name [25], specialty[15];
    float avg;

}student;

void enter_student(student *s);
int search_student(char file_name[], int id);
void add_student(char file_name[], student s);
void display_stud_avg10(char file_name[]);
void change_specialty(char file_name[], int id, char specialty[]);


#endif // STUDENT_H_INCLUDED
