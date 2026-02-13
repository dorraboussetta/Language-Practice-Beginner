#ifndef TRAVELER_H_INCLUDED
#define TRAVELER_H_INCLUDED

typedef struct {
    char id[10], name[20], address[20];
    int nb_trips;

}Traveler;

int menu();
int nbTravelers(char file_name[]);
void enterTraveler(Traveler *ptv);
Traveler* Load_data(char file_name[], int *n);
void save_data(char file_name[], Traveler *tab, int n);
int find_traveler(Traveler *tab, char id[], int n);
Traveler* add(Traveler tr, Traveler *tab, int *n);
void delete_traveler(Traveler *tab, char id[], int *n);
void display_travelers(Traveler *tab, int n);
void release(Traveler *tab);

#endif // TRAVELER_H_INCLUDED
