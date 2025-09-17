#include <stdio.h>
#include <stdlib.h>


/*
 * This program calculates a worker's salary based on
 * basic hours and overtime hours.
 * - Basic hours rate: 3.397
 * - Overtime hours rate: 4.322
 * - Final salary = gross_salary * 1.978
 */

int main()
{
    int basic_hours, overtime_hours;
    float gross_salary, salary;

    printf("Enter the number of basic hours: ");
    scanf("%d", &basic_hours);
    printf("Enter the number of overtime hours: ");
    scanf("%d", &overtime_hours);

    gross_salary = 3.397 * basic_hours + 4.322 * overtime_hours;
    salary = gross_salary * 1.978;
    printf("The salary is: %.2f", salary);

    return 0;
}
