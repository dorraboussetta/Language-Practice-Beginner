#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main() {
    int choice;

    do {

        do {

        printf("\n=== MAIN MENU ===\n");
        printf("1. Add a student.\n");
        printf("2. Display students with an average grade greater than or equal to 10.\n");
        printf("3. Modify a student’s specialty.\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Validate input
        if (choice < 1 || choice > 4) printf("Invalid choice! Please enter a number between 1 and 4.\n");

         } while (choice < 1 || choice > 4);

        // Execute based on user choice
        switch (choice) {
            case 1: {
                student s;
                enter_student(&s);
                add_student("Student.bin", s);
                break;
            }

            case 2: {
                display_stud_avg10("Student.bin");
                break;
            }

            case 3: {
                int id;
                char specialty[20];
                printf("Enter the id of the student: \n"); scanf("%d", &id);
                printf("Enter the specialty of the student: \n"); fflush(stdin); scanf("%s",specialty);
                change_specialty("Student.bin", id, specialty);
                break;
            }

            case 4: {
                printf("Thank you for using this program! \n");
                break;
            }

        }

    } while (choice != 4);

    return 0;
}
