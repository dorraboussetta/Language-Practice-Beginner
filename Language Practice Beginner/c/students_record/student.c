#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void enter_student(student *s){
    do {
            printf("Enter the id of the student: \n"); scanf("%d", &s->id);
    } while (s->id<=0);
    printf("Enter the name of the student:\n"); fflush(stdin); gets(s->name);
    do {
            printf("Enter the average of the student: \n"); scanf("%f", &s->avg);
    } while (s->avg<0);
    printf("Enter the specialty of the student: \n"); fflush(stdin); gets(s->specialty);

}

int search_student(char file_name[], int id){
    FILE *f=NULL;
    student s;
    int found=0;
    f=fopen(file_name, "rb");


    while (fread(&s, sizeof(student), 1, f) && found==0) {
        if (s.id==id) found=1;
    }
    fclose(f);

    return found;

}

void add_student(char file_name[], student s){
    FILE *f=NULL;

    f=fopen(file_name, "ab");

    if (search_student(file_name, s.id)==0) fwrite(&s, sizeof(student),1,f);
    else printf("A student with this id already exists.\n");

    fclose(f);
}

void display_stud_avg10(char file_name[]) {
    FILE *f=NULL;
    student students[40], s;
    int num_stud=0, min;

    f=fopen(file_name, "rb");

    while (fread(&s, sizeof(student), 1, f)) {
            if (s.avg>=10) {
                students[num_stud]=s;
                num_stud++;

            }
        }

    for (int stud=0; stud<num_stud; stud++) {
            min=stud;
            for (int st=stud; st<num_stud; st++) {
                if (students[st].avg<students[min].avg) min=st;
            }
            s=students[stud];
            students[stud]=students[min];
            students[min]=s;

    }

    for (int i=0; i<num_stud; i++) printf("Student %d: ID: %d, Name: %s, Avg; %.2f, Specialty: %s\n", i+1, students[i].id, students[i].name, students[i].avg, students[i].specialty);
    if (num_stud==0) printf("No students with an average less than or equal to 10.\n");
    fclose(f);

}

void change_specialty(char file_name[], int id, char specialty[]){
    FILE *f=NULL, *f_temp=NULL;
    student s;


    f=fopen(file_name, "rb");
    f_temp=fopen("temp.bin", "wb");


            while (fread(&s, sizeof(student), 1, f)) {
                    if(s.id==id) {
                        strcpy(s.specialty,specialty);

                    }

                        fwrite(&s, sizeof(student), 1, f_temp);

                    }

    fclose(f);
    fclose(f_temp);

    remove(file_name);

    rename("temp.bin", file_name);
       }


