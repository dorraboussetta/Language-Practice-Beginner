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


#endif // TRAIN_H_INCLUDED
