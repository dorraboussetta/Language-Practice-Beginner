#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Traveler.h"

int menu(){
        int choice;
        do {

        printf("\n=== MAIN MENU ===\n");
        printf("1. Add a traveler.\n");
        printf("2. Search for a traveler by its id.\n");
        printf("3. Delete a traveler.\n");
        printf("4. Display travelers.\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);


        if (choice < 1 || choice > 5) printf("Invalid choice! Please enter a number between 1 and 5.\n");

         } while (choice < 1 || choice > 5);
        return choice;

}

int nbTravelers(char file_name[]){
    FILE *f=NULL;
    int nb=0;
    Traveler t;

    f=fopen(file_name, "rb");

    if (f!=NULL){
             while (fread(&t, sizeof(Traveler), 1, f)) nb++;
             fclose(f);
    }
    else printf("No file with this name.\n");
    return nb;
}

void enterTraveler(Traveler *ptv){
    printf("Enter the identifier of the traveler: \n"); fflush(stdin); gets(ptv->id);
    printf("Enter the name of the traveler: \n"); fflush(stdin); gets(ptv->name);
    printf("Enter the address of the traveler: \n"); fflush(stdin); gets(ptv->address);
    printf("Enter the number of trips of the traveler: \n"); scanf("%d", &ptv->nb_trips);
}

Traveler* Load_data(char file_name[], int *n){
    FILE *f=NULL;
    Traveler *t=NULL;

    *n=nbTravelers(file_name);
    f=fopen(file_name, "rb");

    if (f!=NULL){
        if (*n>0) {
        t=(Traveler*)malloc(*n * sizeof(Traveler));
        if (t!=NULL) {
            for (int index=0; index<*n; index++) fread(t+index, sizeof(Traveler), 1, f);
            }
        }
        fclose(f);
        printf("File loaded.\n");
    }
    else {
            f=fopen(file_name, "wb");
            if (f!=NULL) {
                    fclose(f);
                    printf("Created a file with this name.\n");
            }
            else printf("Error in file creation.\n");

    }

    return t;

}

/*Traveler* Load_data(char file_name[], int *n) {
    FILE *f=NULL;
    Traveler *t=NULL;
    Traveler tr;

    *n=0;
    f=fopen(file_name, "rb");

    if (f!=NULL){
        while (fread(&tr,sizeof(Traveler), 1, f)){
        (*n)++;
        t=(Traveler*)realloc(t, (*n)*sizeof(Traveler));
        if (t!=NULL){
            t[*n-1]=tr;
            printf("Data loaded.\n");
        }
        else printf("Dynamic allocation failed.\n");
    }
        fclose(f);
    }
    else {
            f=fopen(file_name, "wb");
            if (f!=NULL) {
                    fclose(f);
                    printf("Created a file with this name.\n");
            }
            else printf("Error in file creation.\n");

    }

    return t;

} */
void save_data(char file_name[], Traveler *tab, int n){
    FILE *f=NULL;

    f=fopen(file_name, "wb");
    if (f!=NULL) {
    for (int index=0; index<n; index++) fwrite(tab+index, sizeof(Traveler), 1, f);
    fclose(f);
    }
    else printf("File opening failed. \n");

}

int find_traveler(Traveler *tab, char id[], int n){
    int index=0;

    while (index<n && strcmp(tab[index].id,id)!=0) index++;
    if (index<n) return index;
    else return -1;
}

Traveler* add(Traveler tr, Traveler *tab, int *n){
    int pos=find_traveler(tab, tr.id, *n);
    if (pos==-1) {
        tab=(Traveler*)realloc(tab,(*n+1)*sizeof(Traveler));
        if (tab!=NULL){
            tab[*n]=tr;
            (*n)++;
            printf("Traveler added to the record.\n");
        }
    }
    else {
        tab[pos].nb_trips++;
        printf("Traveler already exists. The number of trips was incremented.\n");
    }
    return tab;

}
void delete_traveler(Traveler *tab, char id[], int *n){
    int pos=find_traveler(tab, id, *n);

    if (pos!=-1) {
        for (int index=pos; index<*n-1; index++) tab[index]=tab[index+1];
        (*n)--;
        printf("Traveler successfully deleted.\n");
    }
    else printf("Traveler not found.\n");

}

void display_travelers(Traveler *tab, int n){
    for (int index=0; index<n; index++) {
        printf("ID: %s, name: %s, address; %s, number of trips: %d\n", tab[index].id, tab[index].name, tab[index].address, tab[index].nb_trips);
    }

}
void release(Traveler *tab){
    free(tab);
    printf("Space freed.\n");
}
