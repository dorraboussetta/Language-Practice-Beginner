#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

void save_employee(char file_name[]){
    FILE *f=NULL;
    int n;
    employee e;

    printf("Enter the number of employees:\n"); scanf("%d", &n);
    f=fopen(file_name, "a");

    if (f!=NULL) {
        for (int i=0; i<n; i++)  {
            printf("Enter the first name of the employee number %d:\n", i+1); fflush(stdin); gets(e.fname);
            printf("Enter the last name of  the employee number %d:\n", i+1); fflush(stdin); gets(e.lname);
            printf("Enter the number of children of  the employee number %d:\n", i+1); scanf("%d", &e.num_children);
            fprintf(f, "%s %s %d\n", e.fname, e.lname, e.num_children);
        }
        fclose(f);

    }
    else printf("No file with this name");


}

void search_employee(char file_name[], char employee_fname[]){
    FILE *f=NULL;
    f=fopen(file_name, "r");
    employee e;
    int found=0;

    if (f!=NULL){
        while (!feof(f) && found==0) {
            if (fscanf(f, "%s %s %d", e.fname, e.lname, &e.num_children)==3) {
                if (strcmp(e.fname, employee_fname)==0) {
                    printf("Employee found! \n"); found=1;
                }
            }

        }
        if (found==0) printf("No employee with this name found.\n");

    }
    else printf("No file with this name.\n");
    fclose(f);

}

void display_emp(char file_name[], int n){
    FILE *f=NULL;
    f=fopen(file_name, "r");
    employee e;

    if (f!=NULL){
        while (!feof(f)) {
            if (fscanf(f, "%s %s %d", e.fname, e.lname, &e.num_children)==3) {
                if (e.num_children>=n) {

                    printf("This employee has more than %d children: %s %s %d \n", n, e.fname, e.lname, e.num_children);
                }
            }

        }


    }
    else printf("No file with this name.\n");
    fclose(f);


}

void delete_employee(char file_name[]){
    FILE *f1=NULL, *f2=NULL;
    employee e;

    f1=fopen(file_name, "r");
    f2=fopen("temp.txt", "w");

    if (f1!=NULL && f2!=NULL) {
        while (!feof(f1)) {
            if (fscanf(f1, "%s %s %d", e.fname, e.lname, &e.num_children)==3) {
                if (e.num_children!=0) {
                    fprintf(f2, "%s %s %d\n", e.fname, e.lname, e.num_children);
                }
            }
        }

        fclose(f1); fclose(f2);
        remove(file_name);
        rename("temp.txt", file_name);

    }
    else printf("No file with this name.\n");
}




















