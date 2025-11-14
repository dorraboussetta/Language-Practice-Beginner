#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 

This program manages imported products, each defined by an ID, quantity sold, and a 3×2 price matrix.
The matrix stores float purchase and sale prices for three currencies: 
    row 0 = dinar, row 1 = euro, row 2 = USD; 
    column 0 = purchase price, column 1 = sale price.
The system allows entering products, displaying their data, analyzing totals, and performing additional operations on the stored information. */

typedef struct {
    char id[15];
    int quantity;
    float price[3][2];

} product;

int main() {
    int choice;
    product prod[50];
    int num_p=0;

    float tabSales[50];



    do {

        do {
        // Display the menu
        printf("\n=== MAIN MENU ===\n");
        printf("1. Add a product to the end of a one-dimensional array of products\n");
        printf("2. Display the list of products whose sold quantity exceeds a threshold entered by the user. \n");
        printf("3. Find and display, for a given product identified by its ID, the currency in which the unit sales margin is the highest. \n");
        printf("4. Calculate and display, in the first currency (Dt), the total sales price of each product. \n");
        printf("5. Sort the product array in ascending order based on the total sales price in the first currency (Dt)and display the sorted list.\n");
        printf("6. Quit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        // Validate input
        if (choice < 1 || choice > 6) printf("Invalid choice! Please enter a number between 1 and 7.\n");

         } while (choice < 1 || choice > 6);

        // Execute based on user choice
        switch (choice) {
            case 1: {

                int index=0, no_prod=1;
                char identifier[15];

                if (num_p!=0) no_prod=0;

                printf("Enter the identifier of the product: \n"); fflush(stdin); gets(identifier);

                 while (index<num_p  && strcmp(prod[num_p-1].id, identifier)!=0) index++;


                 if (index<num_p && no_prod==0) printf("The product already exists.\n");
                 else  {

                    num_p++;
                    strcpy(prod[num_p-1].id, identifier);
                    printf("Enter the quantitity sold: \n"); scanf("%d", &prod[num_p-1].quantity);

                    printf("Enter the purchase price in dt: \n"); scanf("%f", &prod[num_p-1].price[0][0]);
                    printf("Enter the sale price in dt: \n"); scanf("%f", &prod[num_p-1].price[0][1]);
                    printf("Enter the purchase price in eur: \n"); scanf("%f", &prod[num_p-1].price[1][0]);
                    printf("Enter the sale price in eur: \n"); scanf("%f", &prod[num_p-1].price[1][1]);
                    printf("Enter the purchase price in usd: \n"); scanf("%f", &prod[num_p-1].price[2][1]);
                    printf("Enter the sale price in usd: \n"); scanf("%f", &prod[num_p-1].price[2][2]);



                 }



                break;
            }

            case 2: {
                int threshold;

                printf("Enter the threshold: \n"); scanf("%d", &threshold);

                for (int p=0; p<num_p; p++) {

                    if (prod[p].quantity > threshold) {

                        printf("id: %s\n", prod[p].id);
                        printf("Quantity: %d\n", prod[p].quantity);
                        printf("Prices: \n");
                        for (int row=0; row<=2; row++) {

                            for (int col=0; col<=1; col++) {
                                printf("%.2f |", prod[p].price[row][col]);

                            }
                            printf("\n");
                        }



                    }

                }



                break;
            }

            case 3: {

                int index=0, row=0,col=0, max_currency=0;
                float margin, max_margin=0;
                char identifier[15];



                printf("Enter the identifier of the product: \n"); fflush(stdin); scanf("%s", identifier);

                 while (index<num_p  && strcmp(prod[index].id, identifier)!=0) index++;


                 if (index==num_p) printf("No product with this id.\n");
                 else  {

                     max_margin=prod[index].price[0][1]-prod[index].price[0][0];

                        while (row<=2 ) {

                            margin=prod[index].price[row][col+1]-prod[index].price[row][col];

                            if(margin>max_margin) {
                                max_margin=margin;
                                max_currency=row;

                            }
                            margin=0;
                            row++;
                        }

                        if (max_currency==0) printf("The currency with the max margin is dt\n");
                        else if (max_currency==1) printf("The currency with the max margin is eur\n");
                        else if (max_currency==2) printf("The currency with the max margin is usd\n");





                 }


                break;
            }

            case 4: {

                printf("The sale prices for each product in dt: \n");

                for (int index=0; index<num_p; index++) {

                    tabSales[index]=prod[index].price[0][1] * prod[index].quantity;
                    printf("%.2f |", tabSales[index]);
                }
                printf("\n");



                break;
            }

            case 5: {

                float temp;
                product temp_prod;
                int j;

                for (int index=1; index<num_p; index++) {

                    temp=tabSales[index];
                    temp_prod=prod[index];
                    j=index-1;

                    while (j<=0 && tabSales[j]>temp) {
                        tabSales[j+1]=tabSales[j];
                        prod[j+1]=prod[j];
                        j--;

                    }
                    tabSales[j+1]=temp;
                    prod[j+1]=temp_prod;


                }

                for (int index=0; index<num_p; index++) {

                        printf("id: %s\n", prod[index].id);
                        printf("Quantity: %d\n", prod[index].quantity);
                        printf("Prices: \n");
                        for (int row=0; row<=2; row++) {

                            for (int col=0; col<=1; col++) {
                                printf("%.2f |", prod[index].price[row][col]);

                            }
                            printf("\n");
                        }
                        printf("\n");

                }


                break;
            }

            case 6: {

                printf("Thank you for using this application! \n");
                break;
            }

        }

    } while (choice != 6);

    return 0;
}
