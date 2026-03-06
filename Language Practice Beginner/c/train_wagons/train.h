#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED

typedef struct {
    int number, status;
    char type[11];

}wagon;

typedef struct Node {
    wagon wag;
    struct Node *next;

}Node;

typedef struct Node *List;

List add_locomotive_head(List w);
List add_wagon_tail(List w);
int search_wagon(List w, int number);
void display_train(List w);
List delete_failed_wg(List w);
//void delete_failed_wg_from_list(char file_name[]);
List insert_wagon(List w, int number);
List free_wagons(List w);
List add_wagon_from_file(List w, wagon New);
List load_train(List w, char file_name[]);
void save_train(List w, char file_name[]);


#endif // TRAIN_H_INCLUDED
