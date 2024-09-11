#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAX_ETUDIANTS 1000
int nombre_etudiants = 0;

void menu_principale();
void ajouter_un_etudiant();
void modifier_ou_supprimer();
void afficher_details();
void moyenne_generale();
void afficher_totale_etudiant();
void nombre_etudiant_dans_departement();
void etudiants_superieur_a_certain_seuil();
void les_trois_meilleures_notes();


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
          modifier_ou_supprimer();
          break;
        case 3:
          afficher_details();
          break;
        case 4:
          moyenne_generale();
          break;
        case 5:
          afficher_totale_etudiant();
          nombre_etudiant_dans_departement();
          les_trois_meilleures_notes();
          etudiants_superieur_a_certain_seuil();
          break;
    }
   }while (reponse != 8);
   
}


void menu_principale(){
    printf("\nApplication de Gestion des etudiants d'universite\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
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
        printf("Selectionner Votre departement (math - physique - chimie - informatique - biologie): ");
        scanf("%s", &etudiants[nombre_etudiants].departement);
        printf("Note Generale: ");
        scanf("%f", &etudiants[nombre_etudiants].note_generale);
        printf("\nEtudiant ajouter avec success\n");
        nombre_etudiants++;
    
}

void modifier_ou_supprimer(){
    int choix, id, verifier, question;
    printf("\nTu veux: \n1.Modifier les details d'un etudiant\n2.Supprimer les details d'un etudiant\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    if (choix == 1){
        printf("Saisez ID de l'etudiant: ");
        scanf("%d", &id);

        for (int i = 0; i < nombre_etudiants; i++){
         if(etudiants[i].id == id){
           verifier = 1;
           printf("Nom: ");
           scanf("%s", &etudiants[id - 1].nom);
           printf("Prenom: ");
           scanf("%s", &etudiants[id -1].prenom);
           printf("Date de naissance: \n");
           printf("Jour: ");
           scanf("%d", &etudiants[id - 1].date_de_naissances.jour);
           printf("Mois: ");
           scanf("%d", &etudiants[id - 1].date_de_naissances.mois);
           printf("Annee: ");
           scanf("%d", &etudiants[id - 1].date_de_naissances.annee);
           printf("Selectionner Votre departement (math - physique - chimie - informatique - biologie - geologie): ");
           scanf("%s", &etudiants[id - 1].departement);
           printf("Note Generale: ");
           scanf("%f", &etudiants[id - 1].note_generale);
           printf("\nEtudiant ajouter avec success\n");
         }
        }

        if (verifier != 1){
            printf("Invalid ID\n");
        }
    }
    else if (choix == 2){
        printf("Saisez ID de l'etudiant: ");
        scanf("%d", &id);
        printf("Voulez vous vraiment supprimer (1-Y/2-N): ", etudiants[id].nom, etudiants[id].prenom);
        scanf("%d", &question);
        if (question == 1){
            for (int i = id - 1; i < nombre_etudiants; i++){
                etudiants[i] = etudiants[i+1];
            }
            nombre_etudiants -= 1;
            printf("\netudiant supprimer avec success\n");
        }else{
            printf("\nOperation annule\n");
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

void moyenne_generale(){
    int somme_math = 0;
    int somme_physique = 0;
    int somme_chimie = 0;
    int somme_info = 0;
    int somme_biologie = 0;
    float moyenne_math = 0;
    float moyenne_physique = 0;
    float moyenne_chimie = 0;
    float moyenne_info = 0;
    float moyenne_biologie = 0;
    int finale = 0;
    float moyenne = 0;
    for (int i = 0; i < nombre_etudiants; i++){
        strcpy(etudiants[i].departement, strlwr(etudiants[i].departement));
    }
    // for (int i = 0; i < nombre_etudiants; i++){
    //       if(strcmp(etudiants[i].departement, "math") == 0){
    //         somme_math = somme_math + (i + 1);
    //       }
    //       if(strcmp(etudiants[i].departement, "physique")  == 0){
    //         somme_physique = somme_physique +1;
    //       }
    //       if(strcmp(etudiants[i].departement, "chimie")  == 0){
    //         somme_chimie = somme_chimie + 1;
    //       }
    //       if(strcmp(etudiants[i].departement, "informatique")  == 0){
    //         somme_info = somme_info + 1;
    //       }
    //       if(strcmp(etudiants[i].departement, "biologie")  == 0){
    //         somme_biologie = somme_biologie + 1;
    //       }
    // }

    // int finale1 = 0;
    // int finale2 = 0;
    // int finale3 = 0;
    // int finale4 = 0;
    // int finale5 = 0;

    // for (int i = 0; i < nombre_etudiants; i++){
    //     if(strcmp(etudiants[i].departement, "math") == 0){
    //         finale1 = finale1 + etudiants[i].note_generale;
    //         moyenne_math = finale1 / somme_math;
    //       }
    //     if(strcmp(etudiants[i].departement, "physique")  == 0){
    //         finale2 = finale2 + etudiants[i].note_generale;
    //         moyenne_physique = finale2 / somme_physique;
    //       }
    //     if(strcmp(etudiants[i].departement, "chimie")  == 0){
    //         finale3 = finale3 + etudiants[i].note_generale;
    //         moyenne_chimie = finale3 / somme_chimie;
    //       }
    //     if(strcmp(etudiants[i].departement, "informatique")  == 0){
    //         finale4 = finale4 + etudiants[i].note_generale;
    //         moyenne_info = finale4 / somme_info;
    //       }
    //     if(strcmp(etudiants[i].departement, "biologie")  == 0){
    //         finale5 = finale5 + etudiants[i].note_generale;
    //         moyenne_biologie = finale5 / somme_biologie;
    //       }
    // }
    
    // printf("le moyenne generale de departement Math: %.2f\n", moyenne_math);
    // printf("le moyenne generale de departement Physique: %.2f\n", moyenne_physique);
    // printf("le moyenne generale de departement Chimie: %.2f\n", moyenne_chimie);
    // printf("le moyenne generale de departement Informatique: %.2f\n", moyenne_info);
    // printf("le moyenne generale de departement Biologie: %.2f\n", moyenne_biologie);

    for (int i = 0; i < nombre_etudiants; i++){
        moyenne = moyenne + etudiants[i].note_generale;
    }
    printf("Le moyenne generale de l'universite: %.2f\n", moyenne / nombre_etudiants);

    
}

void afficher_totale_etudiant(){
    int totale_etudiant = 0;
    for (int i = 0; i < nombre_etudiants; i++){
        totale_etudiant  = etudiants[i].id;
    }
    printf("Le totale etudiant inscrits: %d\n", totale_etudiant);
}

void nombre_etudiant_dans_departement(){
    int nombre_math = 0;
    int nombre_physique = 0;
    int nombre_chimie = 0;
    int nombre_info = 0;
    int nombre_biologie = 0;
    int nombre_geologie = 0;
    for (int i = 0; i < nombre_etudiants; i++){
        if(strcmp(etudiants[i].departement, "math") == 0){
            nombre_math++;
        }
        if(strcmp(etudiants[i].departement, "physique")  == 0){
            nombre_physique++;
        }
        if(strcmp(etudiants[i].departement, "chimie")  == 0){
            nombre_chimie++;
        }
        if(strcmp(etudiants[i].departement, "informatique")  == 0){
            nombre_info++;
        }
        if(strcmp(etudiants[i].departement, "biologie")  == 0){
            nombre_biologie++;
        }
    }

    printf("Le nombre des etudiant dans le departement Math: %d\n", nombre_math);
    printf("Le nombre des etudiant dans le departement physique: %d\n", nombre_physique);
    printf("Le nombre des etudiant dans le departement Chimie: %d\n", nombre_chimie);
    printf("Le nombre des etudiant dans le departement Informatique: %d\n", nombre_info);
    printf("Le nombre des etudiant dans le departement biologie: %d\n", nombre_biologie);
    
}

void etudiants_superieur_a_certain_seuil(){
    float seuil;
    printf("Sasaiez la seuil: ");
    scanf("%f", &seuil);
    for (int i = 0; i < nombre_etudiants; i++){
        if (etudiants[i].note_generale >= seuil){
            printf("\n");
            printf("ID: %d\n", etudiants[i].id);
            printf("Le Nom: %s\n", etudiants[i].nom);
            printf("Le Prenom: %s\n", etudiants[i].prenom);
            printf("Date de naissanec: %d-%d-%d\n", etudiants[i].date_de_naissances.jour, etudiants[i].date_de_naissances.mois, etudiants[i].date_de_naissances.annee);
            printf("Le Departement: %s\n", etudiants[i].departement);
            printf("La Note generale: %.2f\n", etudiants[i].note_generale);
            printf("\n");
        }
    }
}

void les_trois_meilleures_notes(){
    float max1, max2, max3;
    max1 = max2 = max3 = etudiants[0].note_generale;
    for (int i = 0; i < nombre_etudiants; i++){
        if (max1 < etudiants[i].note_generale){
            max3 = max2;
            max2 = max1;
            max1 = etudiants[i].note_generale;
        }else if (max1 > max2 && max2 < etudiants[i].note_generale ){
            max3 = max2;
            max2 = etudiants[i].note_generale;
        }else if(max1 > max2 && max2 > max3 && max3 < etudiants[i].note_generale){
            max3 = etudiants[i].note_generale;
        }
        
    }

    

    printf("Premier note: %.2f\n", max1);
    printf("deuxieme note: %.2f\n", max2);
    printf("troisieme note: %.2f\n", max3);
}