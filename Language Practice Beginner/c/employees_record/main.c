#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

int main()
{
    char emp_name[10];
    int n_children;

    save_employee("number_of_children.txt");

    printf("Enter the employee name: \n"); fflush(stdin); gets(emp_name);
    search_employee("number_of_children.txt", emp_name);

    printf("Enter the number of children: \n"); scanf("%d", &n_children);
    //display_emp("number_of_children.txt", n_children);

    delete_employee("number_of_children.txt");

    return 0;
}
