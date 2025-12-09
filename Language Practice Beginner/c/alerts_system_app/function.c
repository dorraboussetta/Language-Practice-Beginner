#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
personnel fill_personnel(int index){

    personnel p;


        printf("Enter the login of personnel number %d:\n", index+1);
        fflush(stdin); gets(p.login);
        printf("Enter the password of personnel number %d:\n", index+1);
        fflush(stdin); gets(p.password);

        do {
            printf("Enter the role of personnel number %d(1: agent, 2: administrator):\n", index+1);
            scanf("%d", &p.role);

        }  while (p.role!=1 && p.role!=2);


    return p;

}

int Connect_personnel(char log[15], char pass[15], personnel per[], int n) {

    int index=0;

    while (index<n && (strcmp(per[index].login, log)!=0 ||  strcmp(per[index].password, pass) !=0)) index++;
    if(index<n) return per[index].role;
    else return -1;

}

int search_alert(int id, alert alerts[], int n) {
    int index=0;

    while (index<n && alerts[index].unique_id!=id) index++;

    if (index<n) return index;
    else return -1;

}

void display_menu(int version) {
    if (version==0) {
            printf("\n=== MAIN MENU ===\n");
            printf("1. Use the application.\n");
            printf("2. Quit the application.\n");
            printf("Enter your choice (1-2): ");
    }
    else if (version==1)  {
            printf("\n=== MENU ===\n");
            printf("1. Add a new alert.\n");
            printf("2. Display the list of alerts. \n");
            printf("3. Modify the type of an alert given its identifier. \n");
            printf("4. Delete an alert given its identifier.\n");
            printf("5. Quit\n");
            printf("Enter your choice (1-5): ");

        }
    else if (version==2) {
            printf("\n=== MENU ===\n");
            printf("1. Display the list of alerts.\n");
            printf("2. For a given zone, display the percentage of alerts in that zone compared to the total number of alerts. \n");
            printf("3. Quit\n");
            printf("Enter your choice (1-3): ");

    }

}

alert add_alert(alert alerts[], int num_alerts) {

    alert a;
    int id;
    printf("Enter the zone name: \n"); fflush(stdin); gets(a.zone_name);

    do {
        printf("Enter the unique identifier of the alert.\n"); scanf("%d", &id);

    } while (search_alert(id, alerts, num_alerts)!=-1);

    a.unique_id=id;

    do {
        printf("Enter the type of the alert(1: critical, 0: non-critical): \n"); scanf("%d", &a.type);
    } while (a.type!=0 && a.type!=1);

    return a;


}

void display_alerts(alert alerts[], int num_alerts){
        if (num_alerts==0) {
            printf("No alerts listed yet.\n");
        }

        else {
            for (int index=0; index<num_alerts; index++) {
            printf("Alert number %d:\n", index+1);
            printf("Zone name:\n"); puts(alerts[index].zone_name);
            printf("Unique identifier: %d\n", alerts[index].unique_id);
            printf("Type: ");
            if (alerts[index].type==0) printf("Not critical.\n");
            else printf("Critical.\n");}

        }

}

void modify_alert(alert alerts[], int num_alerts){
        int id, position;

        if (num_alerts==0) printf("NO alerts listed yet.\n");
        else {
            printf("Enter the unique identifier of the alert: \n"); scanf("%d", &id);
            position=search_alert(id, alerts, num_alerts);
            if (position==-1) printf("No alert with such id.\n");
            else {

                 printf("The type of this alert is: %d. Enter the new type:\n", alerts[position].type);
                 scanf("%d", &alerts[position].type);
                 printf("Type successfully modified.\n");

            } }

}

void delete_alert(alert alerts[], int num_alerts) {
    int id, position;

    printf("Enter the unique identifier of the alert: \n"); scanf("%d", &id);
    position=search_alert(id, alerts, num_alerts);
    if (position==-1) printf("No alert with such id.\n");
    else {

         for (int index=position; index<num_alerts-1; index++) alerts[index]=alerts[index+1];
         num_alerts--;

    }
}

void alerts_percentage(alert alerts[], int num_alerts){
    char zone[15];
    int num_in_zone=0;
    float percentage;

    if (num_alerts==0) printf("No alerts listed yet.\n");
    else {
        printf("Enter the zone: \n"); fflush(stdin); gets(zone);

        for (int index=0; index<num_alerts; index++) {
            if (strcmp(zone, alerts[index].zone_name)==0) num_in_zone++;

        }
        percentage= (float)num_in_zone/num_alerts*100;
        printf("Percentage of alerts in this zone is: %.2f%%\n", percentage);
        }


}

