#include <stdbool.h>
struct PERSON
{
    char nom[50];
    char prenom[50];
    long  id;
    long telephone;
}; typedef struct PERSON person;
struct ROOM
{ int numero;
    int num_lits;
    float prix;
    bool dispo;
};typedef struct ROOM room;

struct RESERVATION
{   int num;
      long id_client;
    int numero_room;
};typedef struct RESERVATION reservation;
void ajoutclient(person*,int );
void supprimerclient(person*,int);
void modifierclient(person *  , int );
void affichageclients(person * , int);
void ajoutchambre(room * , int );
void supprimerchambre(room * , int);
void modifierchambre(room * , int );
void affichagechambre(room* , int);
void ajoutreservation(reservation * ,room *, int,int);
void supprimerreservation(reservation * , int);
void modifierreservation ( reservation * , int );
void affichagereservation(reservation *,int,room*);
void allocationclient(person**);
void allocationchambre(room**);
void allocationreserve(reservation**);
