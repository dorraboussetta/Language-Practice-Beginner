#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*This program manages a collection of warehouses, each with shelves, product counts, product type, manager, and city.
It allows adding warehouses, updating shelves and managers, searching and filtering by different conditions, and deleting warehouses based on specific criteria.
All interactions are handled through a menu-driven system until the user chooses to quit.*/


typedef struct Warehouse {
    int identifier, num_shelves;
    char product_type[10], city[8];
    int num_products[50];
    char manager_name[15];


} warehouse;



int main()
{
    warehouse wh[50];
    int num_wh=0, choice;


    do {

            do {
        // Display the menu
        printf("\n=== MAIN MENU ===\n");
        printf("1. Add a new warehouse\n");
        printf("2. Add products to an empty shelf\n");
        printf("3. Display the warehouse containing products of a type entered by the user.\n");
        printf("4. Display the name of the manager and the city of the warehouse containing the greatest number of  products.\n");
        printf("5. Change the manager of a user-selected warehouse.\n");
        printf("6. Calculate the number of warehouses located in a city entered by user.\n");
        printf("7. Display the warehouse where the number of products in each department is below a maximum threshold entered by the user. \n");
        printf("8. Delete the first empty warehouse. \n");
        printf("9. Display a warehouse. \n");
        printf("10. Quit\n");
        printf("Enter your choice (1-10):");
        scanf("%d", &choice);

        if (choice < 1 || choice > 10) printf("Invalid choice! Please enter a number between 0 and 8.\n");

        } while (choice < 1 || choice > 10);

        // Execute based on user choice
        switch (choice) {
            case 1: {
                int id, index=0, no_warehouses=1;

                if (num_wh!=0) no_warehouses=0;

                printf("Enter the identifier of the warehouse: \n"); scanf("%d", &id);

                 while (index<num_wh  && wh[index].identifier!=id) index++;


                 if (index<num_wh && no_warehouses==0) printf("The warehouse already exists.\n");
                 else  {

                    num_wh++;
                    wh[num_wh-1].identifier=id;
                    printf("Enter the number of shelves: \n"); scanf("%d", &wh[num_wh-1].num_shelves);

                    for (int shelf=0; shelf<wh[num_wh-1].num_shelves; shelf++) {
                            wh[num_wh-1].num_products[shelf]=0;
                    }
                    fflush(stdin);
                    do {
                    printf("Enter the products type(clothing, food, spare parts): \n"); gets(wh[num_wh-1].product_type);
                    } while (strcmp(wh[num_wh-1].product_type, "clothing")!=0 && strcmp(wh[num_wh-1].product_type, "food")!=0 && strcmp(wh[num_wh-1].product_type, "spare parts")!=0);

                    printf("Enter the manager's name: \n"); gets(wh[num_wh-1].manager_name);

                    do {
                        printf("Enter the city's name (tunis, sousse, bizerte)\n"); gets(wh[num_wh-1].city);
                    } while (strcmp(wh[num_wh-1].city, "tunis")!=0  && strcmp(wh[num_wh-1].city, "sousse")!=0 && strcmp(wh[num_wh-1].city, "bizerte")!=0);


                 }




                break;
            }

            case 2: {

                int id, num_prod;
                printf("Enter the identifier of the warehouse\n"); scanf("%d", &id);

                int index=0, shelf;

                while (index<num_wh && wh[index].identifier!=id) index++;

                if (index>=num_wh) printf("Warehouse not found");
                else {
                    shelf=0;

                    while (shelf<wh[index].num_shelves && wh[index].num_products[shelf]!=0) shelf++;

                    if (shelf>=wh[index].num_shelves) printf("No empty shelves. \n");
                    else {

                            do {
                        printf("Enter the number of products to add: \n"); scanf("%d", &num_prod);
                            } while (num_prod<=0 || num_prod>200);
                        wh[index].num_products[shelf]=num_prod;
                    }



                }

                break;
            }

            case 3: {

                char type[10];

                fflush(stdin);
                 do {
                printf("Enter the product's type(clothing, food, spare parts): \n"); gets(type);
                } while (strcmp(type, "clothing")!=0 && strcmp(type, "food")!=0 && strcmp(type, "spare parts")!=0);

                for (int index=0; index<num_wh; index++) {

                    if (strcmp(wh[index].product_type, type)==0) {
                        printf("Identifier: %d \n", wh[index].identifier);
                        printf("City: %s\n", wh[index].city);
                        printf("Type of products to be stored: %s\n", wh[index].product_type);
                        printf("Manager name: %s\n", wh[index].manager_name);
                        printf("Number of shelves: %d\n", wh[index].num_shelves);

                        printf("Num of products per shelf: \n");

                        for (int shelf=0; shelf<wh[index].num_shelves; shelf++) {
                            printf("%d |", wh[index].num_products[shelf]);
                        }
                        printf("\n");
                    }
                }
                break;
            }

            case 4: {

                int num_prod=0, num_prod_max=0, max_index=0;

                for (int index=0; index<num_wh; index++) {
                    for (int shelf=0; shelf<wh[index].num_shelves; shelf++) num_prod+=wh[index].num_products[shelf];

                    if (num_prod>num_prod_max) {
                        num_prod_max=num_prod;
                        max_index=index;
                    }
                    num_prod=0;
                }

                printf("The name of the manager of the warehouse containing the greatest number of  products: %s\n ", wh[max_index].manager_name);
                printf("The name of the city of the warehouse containing the greatest number of  products: %s\n ", wh[max_index].city);

                break;
            }

            case 5: {

                int id;
                printf("Enter the identifier of the warehouse\n"); scanf("%d", &id);

                int index=0;

                while (index<num_wh && wh[index].identifier!=id) index++;

                if (index>=num_wh) printf("Warehouse not found");
                else {
                    printf("Enter the name of the new manager: \n"); fflush(stdin); gets(wh[index].manager_name);

                }


                break;
            }

            case 6: {

                int number=0;
                char c[8];

                fflush(stdin);

                 do {
                    printf("Enter the city: \n"); gets(c);
                } while (strcmp(c, "tunis")!=0  && strcmp(c, "sousse")!=0 && strcmp(c, "bizerte")!=0);


                for (int index=0; index<num_wh; index++) {
                    if (strcmp(c, wh[index].city)==0) number++;
                }

                printf("The number of warehouses located in this city is %d\n ", number);

                break;
            }

            case 7: {
                int threshold;
                int shelf;

                printf("Enter the threshold: \n"); scanf("%d", &threshold);

                for (int index=0; index<num_wh; index++) {

                    shelf=0;

                    while (shelf<wh[index].num_shelves && wh[index].num_products[shelf]<threshold) shelf++;

                    if (shelf>=wh[index].num_shelves) {
                        printf("Identifier: %d \n", wh[index].identifier);
                        printf("City: %s\n", wh[index].city);
                        printf("Type of products to be stored: %s\n", wh[index].product_type);
                        printf("Manager name: %s\n", wh[index].manager_name);
                        printf("Number of shelves: %d\n", wh[index].num_shelves);

                        printf("Num of products per shelf: \n");

                        for (int shelf=0; shelf<wh[index].num_shelves; shelf++) {
                            printf("%d |", wh[index].num_products[shelf]);
                        }
                        printf("\n");


                    }

                }



                break;
            }

            case 8: {

                int index=0;
                int shelf, found_empty=0;

                while (index<=num_wh-1 && found_empty==0 ) {
                        shelf=0;
                        while (shelf<wh[index].num_shelves && wh[index].num_products[shelf]==0) shelf++;

                        if (shelf>= wh[index].num_shelves) {
                                found_empty=1;

                            for (int w=index; w<num_wh-2; w++) wh[w]=wh[w+1];

                            printf("First empty warehouse deleted successfully. \n"); num_wh--;
                        }

                        index++;


                }
                if (found_empty==0) printf("No empty warehouse found.\n");






                break;
            }

            case 9: {
                int id, index=0;

                printf("Enter the identifier of the warehouse\n"); scanf("%d", &id);

                while (index<num_wh  && wh[index].identifier!=id) index++;

                 if (index>=num_wh) printf("No warehouse with this identifier exists.\n");
                 else  {

                    printf("Enter the identifier of the warehouse you want to display\n"); scanf("%d", &id);
                    printf("Identifier: %d \n", wh[index].identifier);
                    printf("City: %s\n", wh[index].city);
                    printf("Type of products to be stored: %s\n", wh[index].product_type);
                    printf("Manager name: %s\n", wh[index].manager_name);
                    printf("Number of shelves: %d\n", wh[index].num_shelves);

                    printf("Num of products per shelf: \n");

                    for (int shelf=0; shelf<wh[index].num_shelves; shelf++) printf("%d |", wh[index].num_products[shelf]);

                    printf("\n");}


                break;
            }

            case 10: {

                printf("Thank you for using this application! \n");
                break;
            }

        }

    } while (choice != 10);

    return 0;
}
