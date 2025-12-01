#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program manages a travel agency’s customer data for one year.
// It stores customers and their trips, allowing operations like sorting, searching, and statistics.
// Users interact with the system through a simple menu interface.

typedef struct {
    int d,m,y;

}date;

typedef struct {
    char dest[15];
    date day;

}trip;

typedef struct {
    int id, num_trips;
    char first_name[15], last_name[15];
    trip set_trips[100];


} customer;

int main() {
    int choice;
    int n, year;
    customer cus[100];


    do {
    printf("Enter the number of customers: \n"); scanf("%d", &n);
    } while (n<0 || n>100);

    printf("Enter the year: \n"); scanf("%d", &year);


    do {
        // Display the menu
        printf("\n=== MAIN MENU ===\n");
        printf("1. Fill an array with n customers.\n");
        printf("2. Display the array of customers.\n");
        printf("3. Sort the trips of clients in descending date order.\n");
        printf("4. Display the most loyal traveler.\n");
        printf("5. Display the most requested destination for a traveler knowing his ID.\n");
        printf("6. Display the month of the year with the highest number of bookings.\n");
        printf("7. Quit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        // Validate input
        if (choice < 1 || choice > 7) {
            printf("Invalid choice! Please enter a number between 1 and 7.\n");
            continue;
        }

        // Execute based on user choice
        switch (choice) {
            case 1: {

                for (int index=0; index<n; index++) {
                    printf("Enter the id of customer %d: \n", index+1); scanf("%d", &cus[index].id);
                    fflush(stdin);
                    printf("Enter the first name of customer %d: \n", index+1); gets(cus[index].first_name);
                    printf("Enter the last name of customer %d: \n", index+1); gets(cus[index].last_name);
                    printf("Enter the number of trips of customer %d: \n", index+1); scanf("%d", &cus[index].num_trips);

                    for (int tr=0; tr<cus[index].num_trips; tr++) {

                        fflush(stdin);
                        printf("Enter the destination of trip %d: \n", tr+1); gets(cus[index].set_trips[tr].dest);
                        printf("Enter the day of the trip %d: \n", tr+1); scanf("%d", &cus[index].set_trips[tr].day.d);
                        printf("Enter the month of the trip %d: \n", tr+1); scanf("%d", &cus[index].set_trips[tr].day.m);
                        cus[index].set_trips[tr].day.y=year;

                    }



                }




                break;
            }

            case 2: {

                for (int index=0; index<n; index++) {

                    printf("For customer %d\n", index+1);
                    printf("Identification: %d \n", cus[index].id);
                    printf("First name: %s \n", cus[index].first_name);
                    printf("Last name: %s \n", cus[index].last_name);
                    printf("Number of trips: %d\n", cus[index].num_trips);

                    for (int trip=0; trip<cus[index].num_trips; trip++) {
                        printf("Destination: %s, ", cus[index].set_trips[trip].dest);
                        printf("Date: %d| %d| %d\n", cus[index].set_trips[trip].day.d, cus[index].set_trips[trip].day.m, cus[index].set_trips[trip].day.y);


                    }

                    printf("\n");



                }

                break;
            }

            case 3: {

                trip temp;
                int max_date_index;

                for (int index=0; index<n; index++) {


                        for (int tr=0; tr<cus[index].num_trips-1; tr++) {

                            max_date_index=tr;

                            for (int t=tr+1; t<cus[index].num_trips; t++) {

                                    if (cus[index].set_trips[t].day.m > cus[index].set_trips[max_date_index].day.m) max_date_index=t;
                                    else {
                                        if (cus[index].set_trips[t].day.d == cus[index].set_trips[max_date_index].day.d) {
                                            if (cus[index].set_trips[t].day.d > cus[index].set_trips[max_date_index].day.d) max_date_index=t;
                                        }
                                    }



                            }

                            temp=cus[index].set_trips[tr];
                            cus[index].set_trips[tr]=cus[index].set_trips[max_date_index];
                            cus[index].set_trips[max_date_index]=temp;


                        }




                }

                break;
            }

            case 4: {

                int  max_num=0, max_index;

                for (int index=0; index<n; index++) {

                    if (cus[index].num_trips > max_num){
                            max_num=cus[index].num_trips;
                            max_index=index;


                    }

                    }

                    printf("The most loyal customer\n:");
                    printf("Identification: %d \n", cus[max_index].id);
                    printf("First name: %s \n", cus[max_index].first_name);
                    printf("Last name: %s \n", cus[max_index].last_name);
                    printf("Number of trips: %d\n", cus[max_index].num_trips);

                    for (int tr=0; tr<cus[max_index].num_trips; tr++) {
                        printf("Destination: %s, ", cus[max_index].set_trips[tr].dest);
                        printf("Date: %d| %d| %d\n", cus[max_index].set_trips[tr].day.d, cus[max_index].set_trips[tr].day.m, cus[max_index].set_trips[tr].day.y);


                    }


                break;
            }

            case 5: {
                int identification, index=0;
                int req, max_req=0;
                char fav_dest[15], destination[15];

                printf("Enter the id of the traveler: \n"); scanf("%d", &identification);

                while (index<n && cus[index].id!= identification) index++;

                if (index>=n ) printf("No customer with this id.\n");
                else {

                        for (int el=0; el<cus[index].num_trips; el++) {
                            strcpy(destination, cus[index].set_trips[el].dest);

                            req=0;
                            for (int d=0; d<cus[index].num_trips; d++) {
                                    if (strcmp(cus[index].set_trips[d].dest, destination)==0) req++;


                            }

                            if (req>max_req)
                            {
                               strcpy(fav_dest, destination);  max_req=req;
                            }

                             }

                             printf("The customer's fav destination is: %s\n", fav_dest);


                        }







                break;
            }

            case 6: {

                int num, max_num=0, max_month;

                for (int month=1; month<=12; month++ ) {

                     num=0;
                    for (int index=0; index<n; index++) {

                        for (int t=0; t<cus[index].num_trips; t++) {

                            if (cus[index].set_trips[t].day.m == month) num++;

                        }


                    }

                    if (num>max_num){
                        max_month=month;
                        max_num=num;}


                }
                printf("The month with the highest number of bookings is: %d\n", max_month);





                break;
            }

            case 7: {

                printf("Thank you for using this program! \n");
                break;
            }


    }


    } while (choice != 7);

    return 0;
}




























