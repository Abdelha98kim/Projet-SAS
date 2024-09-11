#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAX_ETUDIANTS 1000
int nombre_etudiants = 0;


void menu_principale();
void ajouter_un_etudiant();
void modifier_ou_ajouter();
void afficher_details();


typedef struct{
    int jour;
    int mois;
    int annee;
}naissances;

typedef struct{
    int id;
    char nom[50];
    char prenom[50];
    naissances date_de_naissances;
    float note_generale;
    char departement[20];
}Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];


int main(){
   int reponse; 
   do{
    menu_principale();
    printf("\nEnter Votre choix: ");
    scanf("%d",&reponse);

    switch (reponse){
        case 1:
          ajouter_un_etudiant();
          break;
        case 2:
          modifier_ou_ajouter();
          break;
        case 3:
          afficher_details();
          break;
    }
   }while (reponse != 8);
   
}


void menu_principale(){
    printf("\nApplication de Gestion des etudiants d'universite\n");
    printf("----------------------------------------------------------\n");
    printf("1.Ajouter un etudiant\n");
    printf("2.Modifier ou Supprimer un etudiant\n");
    printf("3.Afficher les details d'un etudiant\n");
    printf("4.Calculer la moyenne generale\n");
    printf("5.Statistiques\n");
    printf("6.Rechercher un etudiant\n");
    printf("7.Trier les etudiants\n");
    printf("8.Quitter\n");
}

void ajouter_un_etudiant(){
        
        etudiants[nombre_etudiants].id = nombre_etudiants + 1;
        printf("Nom: ");
        scanf("%s", &etudiants[nombre_etudiants].nom);
        printf("Prenom: ");
        scanf("%s", &etudiants[nombre_etudiants].prenom);
        printf("Date de naissance: \n");
        printf("Jour: ");
        scanf("%d", &etudiants[nombre_etudiants].date_de_naissances.jour);
        printf("Mois: ");
        scanf("%d", &etudiants[nombre_etudiants].date_de_naissances.mois);
        printf("Annee: ");
        scanf("%d", &etudiants[nombre_etudiants].date_de_naissances.annee);
        printf("Selectionner Votre departement (math - physique - chimie - informatique - biologie - geologie): ");
        scanf("%s", &etudiants[nombre_etudiants].departement);
        printf("Note Generale: ");
        scanf("%f", &etudiants[nombre_etudiants].note_generale);
        printf("\nEtudiant ajouter avec success\n");
        nombre_etudiants++;
    
}

void modifier_ou_ajouter(){
    int choix, id, verifier;
    printf("\nTu veux: \n1.Modifier les details d'un etudiant\n2.Supprimer les details d'un etudiant\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    if (choix == 1){
        printf("Saisez ID de l'etudiant: ");
        scanf("%d", &id);

        for (int i = 0; i < nombre_etudiants; i++){
         if(etudiants[i].id == id){
          verifier = 1;
         }else{
            verifier = 0;
         }
        }

        if(verifier == 1){
           printf("Nom: ");
           scanf("%s", &etudiants[id - 1].nom);
           print("Prenom: ");
           scanf("%s", &etudiants[id -1].prenom);
           printf("Date de naissance: \n");
           printf("Jour: ");
           scanf("%d", &etudiants[nombre_etudiants].date_de_naissances.jour);
           printf("Mois: ");
           scanf("%d", &etudiants[nombre_etudiants].date_de_naissances.mois);
           printf("Annee: ");
           scanf("%d", &etudiants[nombre_etudiants].date_de_naissances.annee);
        }
    }


}

void afficher_details(){
    int id, verifier;
    printf("Saisez ID de L'etudiant: ");
    scanf("%d", &id);
    for (int i = 0; i < nombre_etudiants; i++){
        if(etudiants[i].id == id){
        verifier = 1;
        printf("-------------------------\n");
        printf("\n");
        printf("ID: %d", etudiants[i].id);
        printf("\nNom: %s\n", etudiants[i].nom);
        printf("Prenom: %s\n", etudiants[i].prenom);
        printf("Date de naissance:\n");
        printf(" Jour: %d\n", etudiants[i].date_de_naissances.jour);
        printf(" Mois: %d\n", etudiants[i].date_de_naissances.mois);
        printf(" Annee: %d\n", etudiants[i].date_de_naissances.annee);
        printf("departement: %s\n", etudiants[i].departement);
        printf("Note generale: %.2f\n", etudiants[i].note_generale);
        }
    }

    if (verifier != 1){
        printf("Cette etudiants n'exsite pas");
        printf("\n");
    }
        
}