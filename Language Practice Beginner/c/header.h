#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct {
    char login[15], password[15];
    int role;

}personnel;

typedef struct {
    char zone_name[15];
    int unique_id, type;

}alert;

personnel fill_personnel(int index);
int Connect_personnel(char login[15], char password[15], personnel per[], int n);
int search_alert(int id, alert alerts[], int n);
void display_menu(int version);
alert add_alert(alert alerts[], int num_alerts);
void display_alerts(alert alerts[], int num_alerts);
void modify_alert(alert alerts[], int num_alerts);
void delete_alert(alert alerts[], int num_alerts);
void alerts_percentage(alert alerts[], int num_alerts);

#endif // HEADER_H_INCLUDED
