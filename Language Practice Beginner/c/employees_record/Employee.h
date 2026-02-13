#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct {
    char fname[10], lname[10];
    int num_children;

}employee;

void save_employee(char file_name[]);
void search_employee(char file_name[], char employee_fname[]);
void display_emp(char file_name[], int n);
void delete_employee(char file_name[]);


#endif // EMPLOYEE_H_INCLUDED
