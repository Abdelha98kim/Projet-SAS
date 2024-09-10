#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAX_ETUDIANTS 1000
#define MAX_LENGTH 50

// LES DONNES DE PROGRAMES
typedef struct{
    int id;
    char nom[MAX_LENGTH];
    char prenom[MAX_LENGTH];
    char date_de_naissances[MAX_LENGTH];
    char departement[MAX_LENGTH];
    float note_generale;
}Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];
int nombre_etudiants = 0;
void menu_principale();

int main(){
    menu_principale();
    return 0;
}


void menu_principale(){
    int reponse;
    do{
    printf("\nApplication de Gestion des etudiants dans une universite\n");
    printf("1.Ajouter un etudiant\n");
    printf("2.Modifier un etudiant\n");
    printf("3.Supprimer un etudiant\n");
    printf("4. Afficher les details d'un etudiant\n");
    printf("5. Calculer la moyenne generale\n");
    printf("6. Statistiques\n");
    printf("7. Rechercher un etudiant\n");
    printf("8. Trier les etudiants\n");
    printf("9. Quitter\n");
    printf("Votre Choix: ");
    scanf("%d", &reponse);

    //   switch(reponse){
    //     case 1:
    //         ajouter_un_etudiant();
    //         break;
    //     case 2:
    //         modifier_les_informations();
    //         break;
    //     case 3:
    //         supprimer_un_etudiant();
    //         break;
    //     case 4:
    //         afficher_les_details();
    //         break;
    //     case 5:
    //         calculer_le_moyenne();
    //         break;
    //     case 6:
    //         statistique();
    //         break;
    //     case 7:
    //         chercher_un_etudiant();
    //         break;
    //     case 8:
    //         trier_les_etudiants();
    //         break;
    //     case 9:
    //         printf("Au revoir!\n");
    //         break;
    //     default:
    //         printf("Choix invalid saisez une autre reponse existe dans le menu\n");
    //         break;
    //   }
    }while(reponse != 9);
}

void ajouter_un_etudiant(){

}