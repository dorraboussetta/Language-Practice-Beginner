#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*This program manages daily temperature and humidity measurements and allows interactive analysis through a menu.
The user can display, update, and analyze the measurements, including max/min values, averages, and standard deviation.
The program continues running until the user chooses to quit.*/

int main() {
    int choice;
    int n;
    float temperature[15], humidity[15];

    do {
        printf("Enter the number of daily measurements (max 15): "); scanf("%d", &n);
    } while (n <= 0 || n > 15);

    printf("\nEnter the temperature for each measurement:\n");
    for (int index = 0; index < n; index++) {
        printf("Temperature of measurement %d: ", index + 1);
        scanf("%f", &temperature[index]);
    }

    printf("\nEnter the humidity for each measurement:\n");
    for (int index = 0; index < n; index++) {
        printf("Humidity of measurement %d: ", index + 1);
        scanf("%f", &humidity[index]);
    }

    do {

            do {
        printf("\n=== MAIN MENU ===\n");
        printf("1. Display temperature measurements\n");
        printf("2. Display humidity measurements\n");
        printf("3. Update a measurement\n");
        printf("4. Show maximum and minimum humidity\n");
        printf("5. Show average temperature and humidity\n");
        printf("6. Show standard deviation of humidity\n");
        printf("7. Quit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) printf("Invalid choice! Please enter a number between 1 and 7.\n");
        } while (choice < 1 || choice > 7);

        switch (choice) {
            case 1: {
                printf("Temperature measurements:\n");
                for (int index = 0; index < n; index++) {
                    printf("Measurement %d: %.2f\n", index + 1, temperature[index]);
                }
                break;
            }

            case 2: {
                printf("Humidity measurements:\n");
                for (int index = 0; index < n; index++) {
                    printf("Measurement %d: %.2f\n", index + 1, humidity[index]);
                }
                break;
            }

            case 3: {
                int num, type;
                float new_val;

                printf("1. Update temperature\n");
                printf("2. Update humidity\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (type != 1 && type != 2) {
                    printf("Invalid choice.\n");
                    break;
                }


                   printf("Enter the measurement number to update\n: ");
                scanf("%d", &num);
                if (num < 1 || num > n) {
                    printf("Invalid number.\n");
                    break;
                }


                printf("Enter new value: ");
                scanf("%f", &new_val);
                if (type == 1)
                    temperature[num - 1] = new_val;
                else
                    humidity[num - 1] = new_val;
                printf("Measurement %d updated successfully.\n", num);
                break;
            }

            case 4: {
                float maxH = humidity[0];
                float minH = humidity[0];
                int max_index = 0, min_index = 0;
                for (i = 1; i < n; i++) {
                    if (humidity[i] > maxH) {
                        maxH = humidity[i];
                        max_index = i;
                    }
                    if (humidity[i] < minH) {
                        minH = humidity[i];
                        min_index = i;
                    }
                }
                printf("Maximum humidity: %.2f\n", maxH, max_index + 1);
                printf("Minimum humidity: %.2f \n", minH, min_index + 1);
                break;
            }

            case 5: {
                float sumT = 0, sumH = 0;
                for (i = 0; i < n; i++) {
                    sumT += temperature[i];
                    sumH += humidity[i];
                }
                printf("\nAverage temperature: %.2f\n", sumT / n);
                printf("Average humidity: %.2f\n", sumH / n);
                break;
            }

            case 6: {
                float mean = 0, variance = 0, stdDev;
                for (i = 0; i < n; i++)
                    mean += humidity[i];
                mean /= n;
                for (i = 0; i < n; i++)
                    variance += (humidity[i] - mean) * (humidity[i] - mean);
                stdDev = sqrt(variance / n);
                printf("\nStandard deviation of humidity: %.2f\n", stdDev);
                break;
            }

            case 7: {
                printf("Thank you for using this program.\n");
                break;
            }
        }
    } while (choice != 7);

    return 0;
}
