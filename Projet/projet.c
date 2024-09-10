#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAX_ETUDIANTS 1000
#define MAX_LENGTH 50


typedef struct{
    int id;
    char nom[MAX_LENGTH];
    char prenom[MAX_LENGTH];
    char date_de_naissances[MAX_LENGTH];
    char departement[MAX_LENGTH];
    float note_generale;
}Etudiant;

int main(){
    return 0;
}