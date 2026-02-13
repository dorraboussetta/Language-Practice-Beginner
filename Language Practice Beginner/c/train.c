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

        new_w->next=w;
        w=new_w;

    }
    else printf("Dynamic allocation failed.\n");
    return w;
}

List add_wagon_tail(List w) {
    List new_w, l=w;

    new_w=(Node*)malloc(sizeof(Node));


    if (new_w!=NULL) {
        printf("Hello");
        printf("Enter the wagon number: \n"); scanf("%d", &new_w->wag.number);

        strcpy(new_w->wag.type, "wagon");

        do {
            printf("Enter the wagon status(0 for out of order, 1 for good working order: \n"); scanf("%d", &new_w->wag.status );
        }while(new_w->wag.status!=0 && new_w->wag.status!=1);

        new_w->next=NULL;

        if (w==NULL) w=new_w;
        else {
            while (l->next!=NULL) l=l->next;
            l->next=new_w;
        }
    }
    else printf("Dynamic allocation failed.\n");
    return w;

}

int search_wagon(List w, int number){
    List p=w;

    while (p!=NULL && p->wag.number!=number) p=p->next;

    if (p!=NULL) {
        printf("Wagon number %d: Type: %s, status: %d\n", p->wag.number,p->wag.type, p->wag.status);
        return 1;
    }
    else return 0;

}

void display_train(List w) {
    List p=w;

    while (p!=NULL) {
        printf("Wagon number %d: Type: %s, status: %d\n", p->wag.number,p->wag.type, p->wag.status);
        p=p->next;
    }

}
