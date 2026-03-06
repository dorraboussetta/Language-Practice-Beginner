#include <stdio.h>
#include <stdlib.h>
#include "train.h"
#include "string.h"

List add_locomotive_head(List w){
    List new_w;
    new_w=(Node*)malloc(sizeof(Node));

    if (new_w!=NULL) {
        printf("Enter the wagon number: \n"); scanf("%d", &new_w->wag.number);

        strcpy(new_w->wag.type, "locomotive");

        do {
            printf("Enter the wagon status(0 for out of order, 1 for good working order: \n"); scanf("%d", &new_w->wag.status );
        }while(new_w->wag.status!=0 && new_w->wag.status!=1);

        if (search_wagon(w, new_w->wag.number)==1) {
            printf("A wagon with this number is already on the train!\n"); free(new_w);
        }
        else {

        new_w->next=w;
        w=new_w;
        printf("Locomotive added to the train! \n");
        }



    }
    else printf("Dynamic allocation failed.\n");
    return w;
}

List add_wagon_tail(List w) {
    List new_w, l=w;

    new_w=(Node*)malloc(sizeof(Node));


    if (new_w!=NULL) {
        printf("Enter the wagon number: \n"); scanf("%d", &new_w->wag.number);

        strcpy(new_w->wag.type, "wagon");

        do {
            printf("Enter the wagon status(0 for out of order, 1 for good working order: \n"); scanf("%d", &new_w->wag.status );
        }while(new_w->wag.status!=0 && new_w->wag.status!=1);

        new_w->next=NULL;

        if (search_wagon(w, new_w->wag.number)==1) {
            printf("Wagon already on the train!\n"); free(new_w);
        }
        else {

        if (w==NULL) w=new_w;
        else {
            while (l->next!=NULL) l=l->next;
            l->next=new_w;
        }
            printf("Wagon added to the train! \n");
        }

    }
    else printf("Dynamic allocation failed.\n");
    return w;

}


int search_wagon(List w, int number){
    List p=w;

    while (p!=NULL && p->wag.number!=number) p=p->next;

    if (p!=NULL) return 1;

    else return 0;

}

void display_train(List w) {
    List p=w;

    if (p==NULL) printf("Train is empty!\n");
    while (p!=NULL) {
        printf("Wagon number %d: Type: %s, status: %d\n", p->wag.number,p->wag.type, p->wag.status);
        p=p->next;
    }

}

List delete_failed_wg(List w){
    List p, pred;
    int failed_wg_exist=1, deleted_wagons=0;

    if (w!=NULL) {

        while (failed_wg_exist==1) {
            p=w;
            pred=w;
            while (p!=NULL && p->wag.status!=0)
            {
                pred=p;
                p=p->next;
            }
            if (p==NULL) failed_wg_exist=0;
            else {
                if (p==w){
                    w=w->next;
                    free(p);
                    deleted_wagons++;
                }
                else {
                    pred->next=p->next;
                    free(p);
                    deleted_wagons++;
                }

            }
        }
        if (deleted_wagons==0) printf("No failed wagons found!\n");
        else printf("Deleted %d wagons!\n", deleted_wagons);

    }
    else printf("Empty train.\n");
    return w;

}
/*
void delete_failed_wg_from_list(char file_name[]){
    FILE *f=NULL, *temp=NULL;
    wagon w;

    f=fopen(file_name, "r");
    temp=fopen("temp.txt", "a");

    if (f!=NULL && temp!=NULL) {

    while (!feof(f)) {
                if (fscanf(f, "%d %s %d", &w.number, w.type, &w.status)==3) {
                    if (w.status==1) fprintf(temp, "%d %s %d\n", w.number, w.type, w.status);
                }
    }
    fclose (f);
    fclose(temp);
    }
    else printf("No file with this name.\n");

    remove(file_name);
    rename("temp.txt", file_name);


}*/

/*
List insert_wagon(List w, int number){
    List new_w, successor=w, p=w;

    if (w!=NULL){


    while (p!=NULL && p->wag.number!=number) {
        p=successor;
        if (successor!=NULL) successor=p->next;
    }

    if (p==NULL) printf("No wagon with this number.\n");
    else {

        new_w=(Node*)malloc(sizeof(Node));
        printf("Enter the wagon number: \n"); scanf("%d", &new_w->wag.number);

        do {
            printf("Enter the wagon status(0 for out of order, 1 for good working order: \n"); scanf("%d", &new_w->wag.status );
        }while(new_w->wag.status!=0 && new_w->wag.status!=1);

        new_w->next=successor;
        p->next=new_w;

    }


    }

    else printf("Empty train.\n");
    return w;
}*/

List insert_wagon(List w, int number){
    List new_w, p=w;

    if (w!=NULL){


    while (p!=NULL && p->wag.number!=number) {
        p=p->next;
    }

    if (p==NULL) printf("No wagon with this number.\n");
    else {
        if (strcmp(p->next->wag.type, "locomotive")==0) printf("Insertion error! There is a locomotive after this wagon.\n");
        else {
        new_w=(Node*)malloc(sizeof(Node));
        printf("Enter the wagon number: \n"); scanf("%d", &new_w->wag.number);
        strcpy(new_w->wag.type, "wagon");

        do {
            printf("Enter the wagon status(0 for out of order, 1 for good working order: \n"); scanf("%d", &new_w->wag.status);
        }while(new_w->wag.status!=0 && new_w->wag.status!=1);

        new_w->next=p->next;
        p->next=new_w;
        }

    }

    }

    else printf("Empty train.\n");
    return w;
}
List free_wagons(List w){
    List p=w, temp=w;

    while (p!=NULL) {
        temp=p;
        p=p->next;
        free(temp);
    }
    w=NULL;
    return w;
}

List load_train(List w, char file_name[]){
    FILE *f=NULL;
    wagon new_w;

    f=fopen(file_name, "r");
    if (f==NULL) printf("hello");

    if (f==NULL) {
        printf("No file with this name\n");
        f=fopen(file_name, "w");
        fclose(f);
        printf("Created a file with this name\n");
    }
    else {
        while (!feof(f)) {
            if (fscanf(f, "%d %s %d", &new_w.number, new_w.type, &new_w.status)==3) w=add_wagon_from_file(w, new_w);
        }
        fclose(f);
        printf("Wagons loaded into the list.\n");

    }
    return w;

}

List add_wagon_from_file(List w, wagon New){
    List new_w=NULL, p=w;

    new_w=malloc(sizeof(Node));
    new_w->wag.number=New.number;
    new_w->wag.status=New.status;
    strcpy(new_w->wag.type, New.type);

    new_w->next=NULL;
    if (w==NULL) w=new_w;
    else {
        while (p->next!=NULL) p=p->next;
        p->next=new_w;

    }

    return w;

}

void save_train(List w, char file_name[]){
    FILE *f=NULL;
    List p=w;

    f=fopen(file_name, "w");

    if (f!=NULL){

        while(p!=NULL){
            fprintf(f, "%d %s %d\n", p->wag.number, p->wag.type, p->wag.status);
            p=p->next;
        }
        fclose(f);
        printf("Train loaded into the list.\n");
    }
    else printf("No file with this name.\n");


}

