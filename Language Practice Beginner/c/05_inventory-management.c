#include <stdio.h>

/*
---------------------------------------------------------------------------------------
DESCRIPTION:
This program simulates a basic inventory management system for a store's warehouse.
It allows the user to record, update, and analyze the quantities and prices of products
stored across multiple shelves.

---------------------------------------------------------------------------------------
FUNCTIONALITY:
The program lets the user input the number of shelves and product types, then manage
inventory data through a menu. It supports updating quantities, computing total quantities
and total prices, deleting zero prices, sorting prices in ascending order, and searching
for a specific price value using a binary search.

---------------------------------------------------------------------------------------
CONCEPTS USED:
- Two-dimensional and one-dimensional arrays
- Loops and conditional statements
- Selection sort and binary search algorithms
- Menu-driven program structure
---------------------------------------------------------------------------------------
*/


int main() {
    int choice, num_shelves, num_product_types, new_size;
    int Inventory[20][20], quantities[20];
    float UnitPrices[20], TotalPrices[20];



    do {
        printf("Enter the number of shelves: \n"); scanf("%d", &num_shelves);
    } while (num_shelves<1 || num_shelves>20);

    do {
        printf("Enter the number of product types: \n"); scanf("%d", &num_product_types);
    } while (num_product_types<1 || num_product_types>20);

    new_size=num_product_types;


    for (int i=0; i<num_shelves; i++)
    {
        for (int j=0; j<num_product_types; j++) {
            printf("Enter the number of products in shelf %d column %d: \n", i, j);
            scanf("%d", &Inventory[i][j]);
        }
    }
    printf("Your inventory: \n");
       for (int i=0; i<num_shelves; i++)
    {
        for (int j=0; j<num_product_types; j++) {
            printf("%d | ", Inventory[i][j]);
        }
        printf("\n");
    }

    do {
            do {
                printf("\n=== MAIN MENU ===\n");
                printf("1. Update the quantity of a given shelf\n");
                printf("2. Display the total quantity of each product\n");
                printf("3. Enter the unit price of each product\n");
                printf("4. Calculate and store in a separate array the total price of the products\n");
                printf("5. Delete from the total price array all cells with a price equal to zero\n");
                printf("6. Sort the total prices of the products\n");
                printf("7. Find a price in the array containing the prices\n");
                printf("8. Quit\n");
                printf("Enter your choice (1-8): ");
                scanf("%d", &choice);

                if (choice < 1 || choice > 8) printf("Invalid choice! Please enter a number between 1 and 8.\n");
                } while (choice < 1 || choice > 8);



        switch (choice) {
            case 1: {
                // Update the quantity  of a given shelf
                int shelf, column, newval;
                printf("Enter the shelf of the compartment you want to change the value of: \n"); scanf("%d", &shelf);
                printf("Enter the column of the compartment you want to change the value of: \n");scanf("%d", &column);
                printf("Enter the new value of the compartment shelf %d column %d: \n", shelf, column); scanf("%d", &newval);

               do {
                    printf("Quantity cannot be negative. Try again.\n"); scanf("%d", &newval);
                }  while (newval<0);
                Inventory[shelf][column] = newval;

                printf("Your inventory: \n");

                for (int row=0; row<num_shelves; row++) {
                    for (int col=0; col<num_product_types; col++) {
                        printf("%d | ", Inventory[row][col]);
                    }
                    printf("\n");
                }

                    break;
                }

            case 2: {

                int col, rows;

                for (col=0; col<num_product_types; col++) quantities[col]=0;

                for (col=0; col<num_product_types; col++) {
                    for (rows=0; rows<num_shelves; rows++) {
                        quantities[col]+=Inventory[rows][col];
                    }
                 }
                 printf("Your quantities table is: \n");
                for (int index=0; index<num_product_types; index++) {
                    printf("%d | ",quantities[index]);
                }


                break;
            }

            case 3: {
                for (int col=0; col<num_product_types; col++) {
                    printf("Enter the unit price of product %d: \n", col);
                    scanf("%f", &UnitPrices[col]);
                }
                printf("Unit prices are stored. Your unit prices: \n");
                for (int index=0; index<num_product_types; index++)
                    {
                            printf("%f | ", UnitPrices[index]);
                    }
                    printf("\n");



                break;
            }

            case 4: {
                //Calculate and store in a separate array the total price of the products

                for (int col=0; col<num_product_types; col++) TotalPrices[col]=0;

                for (int product_type=0; product_type<num_product_types; product_type++) {

                    TotalPrices[product_type]= UnitPrices[product_type]*quantities[product_type];

                }
                printf("Total prices are calculated.\n");
                 for (int p=0; p<num_product_types; p++)
                    {
                            printf("%f | ", TotalPrices[p]);
                    }
                    printf("\n");
                break;
            }

            case 5: {
                for (int index=0; index<(num_product_types-1); index++) {
                    if (TotalPrices[index]==0)
                    {   new_size--;
                        for (int el=index; el<new_size; el++) {
                            TotalPrices[el]=TotalPrices[el+1];
                        }
                    }
                }

                printf("All prices equal to 0 are removed.\n"); printf("%d\n", new_size);

                for (int index=0; index<new_size; index++)
                    {
                            printf("%f | ", TotalPrices[index]);
                    }
                    printf("\n");
                break;
            }

            case 6: {
                int min;
                float temp;

                for (int index=0; index<(new_size-1); index++) {
                    min=index;
                    for (int el=index+1; el<new_size; el++) {
                        if (TotalPrices[el]<TotalPrices[min]) min=el;
                    }
                    temp=TotalPrices[index];
                    TotalPrices[index]=TotalPrices[min];
                    TotalPrices[min]=temp;

                }
                printf("The total prices are sorted.\n");
                  for (int index=0; index<new_size; index++)
                    {
                            printf("%f | ", TotalPrices[index]);
                    }
                    printf("\n");
                break;
            }

            case 7: {

                int b,e, mid;
                float x;

                printf("Enter the price you want to look for in the array: \n"); scanf("%f", &x);

                b=0; e=new_size-1;

                do {
                    mid= (b+e) / 2;
                    if (TotalPrices[mid]<x) b=mid+1;
                    if (TotalPrices[mid]>x) e=mid-1;




                } while (TotalPrices[mid]!=x  && b<=e);

                if (TotalPrices[mid]==x) printf("%f is found at index %d\n", x, mid);
                else printf("%f is not found", x);

                break;
            }
            case 8: {

                printf("Thank you for using this program.\n");
                break;
            }
        }

    } while (choice != 8);

    return 0;
}


