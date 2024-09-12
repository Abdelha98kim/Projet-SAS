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
void statistiques();
void afficher_totale_etudiant();
void nombre_etudiant_dans_departement();
void etudiants_superieur_a_certain_seuil();
void les_trois_meilleures_notes();
void nombre_etudiants_reussi_departement();
void rechercher_un_etudiant();
void triage();
void trier_etudtiant_fct_nom();


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
          statistiques();
          break;
        case 6:
          rechercher_un_etudiant();
          break;
        case 7:
          triage();
          break;
    }
   }while (reponse != 8);

   getchar();
   return 0;
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
        int jour, mois, annee;
        etudiants[nombre_etudiants].id = nombre_etudiants + 1;
        printf("Nom: ");
        scanf("%s", &etudiants[nombre_etudiants].nom);
        printf("Prenom: ");
        scanf("%s", &etudiants[nombre_etudiants].prenom);
        printf("Date de naissance: \n");
        do{
        printf("Jour: ");
        scanf("%d", &etudiants[nombre_etudiants].date_de_naissances.jour);
        }while(etudiants[nombre_etudiants].date_de_naissances.jour > 31 || etudiants[nombre_etudiants].date_de_naissances.jour < 0 );
        do{
        printf("Mois: ");
        scanf("%d", &etudiants[nombre_etudiants].date_de_naissances.mois);
        }while(etudiants[nombre_etudiants].date_de_naissances.mois > 12);
        do{
        printf("Annee: ");
        scanf("%d", &etudiants[nombre_etudiants].date_de_naissances.annee);
        }while(etudiants[nombre_etudiants].date_de_naissances.annee < 1900 || etudiants[nombre_etudiants].date_de_naissances.annee > 2022 );
        do{
        printf("Selectionner Votre departement (math - physique - chimie - informatique - biologie): ");
        scanf("%s", &etudiants[nombre_etudiants].departement);
        }while(strcmp(etudiants[nombre_etudiants].departement , "math") != 0 && strcmp(etudiants[nombre_etudiants].departement , "physique") != 0 && strcmp(etudiants[nombre_etudiants].departement , "chimie") != 0 && strcmp(etudiants[nombre_etudiants].departement , "informatique") != 0 && strcmp(etudiants[nombre_etudiants].departement , "biologie") != 0);
        do{
        printf("Note Generale: ");
        scanf("%f", &etudiants[nombre_etudiants].note_generale);
        }while(etudiants[nombre_etudiants].note_generale > 20 || etudiants[nombre_etudiants].note_generale < 0);
        printf("\nEtudiant ajouter avec success\n");
        nombre_etudiants++;
    
}

void modifier_ou_supprimer(){
    int choix, id, verifier, question;
    printf("\nTu veux: \n1.Modifier les details d'un etudiant\n2.Supprimer les details d'un etudiant\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    if (choix == 1){
        for (int i = 0; i < nombre_etudiants; i++){
        printf("-------------------------\n");
        printf("ID: %d| ", etudiants[i].id);
        printf("%s %s\n", etudiants[i].nom, etudiants[i].prenom);
    }
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
        for (int i = 0; i < nombre_etudiants; i++){
        printf("-------------------------\n");
        printf("ID: %d| ", etudiants[i].id);
        printf("%s %s\n", etudiants[i].nom, etudiants[i].prenom);
    }
        printf("Saisez ID de l'etudiant: ");
        scanf("%d", &id);
        printf("Voulez vous vraiment supprimer (1-Y/2-N): ", etudiants[id].prenom);
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
    for (int i = 0; i < nombre_etudiants; i++){
        printf("-------------------------\n");
        printf("ID: %d| ", etudiants[i].id);
        printf("%s %s\n", etudiants[i].nom, etudiants[i].prenom);
    }
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
        printf("Jour: %d\n", etudiants[i].date_de_naissances.jour);
        printf("Mois: %d\n", etudiants[i].date_de_naissances.mois);
        printf("Annee: %d\n", etudiants[i].date_de_naissances.annee);
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
    float finale = 0;
    float moyenne = 0;
    for (int i = 0; i < nombre_etudiants; i++){
        strcpy(etudiants[i].departement, strlwr(etudiants[i].departement));
    }
   
    float finale1 = 0;
    float finale2 = 0;
    float finale3 = 0;
    float finale4 = 0;
    float finale5 = 0;

    for (int i = 0; i < nombre_etudiants; i++){
        if(strcmp(etudiants[i].departement, "math") == 0){
               somme_math++;
            finale1 = finale1 + etudiants[i].note_generale;
            
          }
        else if(strcmp(etudiants[i].departement, "physique")  == 0){
                somme_physique++;
            finale2 = finale2 + etudiants[i].note_generale;
            
          }
        else if(strcmp(etudiants[i].departement, "chimie")  == 0){
               somme_chimie++;
            finale3 = finale3 + etudiants[i].note_generale;
            
          }
        else if(strcmp(etudiants[i].departement, "informatique")  == 0){
               somme_info++;
            finale4 = finale4 + etudiants[i].note_generale;
            
          }
        else if(strcmp(etudiants[i].departement, "biologie")  == 0){
               somme_biologie++;
            finale5 = finale5 + etudiants[i].note_generale;
            
          }
    }
       
       moyenne_math = finale1 / somme_math;
       moyenne_physique = finale2 / somme_physique;
       moyenne_chimie = finale3 / somme_chimie;
       moyenne_info = finale4 / somme_info;
       moyenne_biologie = finale5 / somme_biologie;
    
    printf("le moyenne generale de departement Math: %.2f\n", moyenne_math);
    printf("le moyenne generale de departement Physique: %.2f\n", moyenne_physique);
    printf("le moyenne generale de departement Chimie: %.2f\n", moyenne_chimie);
    printf("le moyenne generale de departement Informatique: %.2f\n", moyenne_info);
    printf("le moyenne generale de departement Biologie: %.2f\n", moyenne_biologie);
    printf("\n");

    for (int i = 0; i < nombre_etudiants; i++){
        moyenne = moyenne + etudiants[i].note_generale;
    }
    printf("Le moyenne generale de l'universite: %.2f\n", moyenne / nombre_etudiants);

    
}

void statistiques(){
    int choix;
  printf("\n");
  printf("Les Statistiques: \n");
  printf("-----------------------\n");
  printf("1-Afficher le nombre total d'etudiants inscrits \n");
  printf("2-Afficher le nombre d'etudiants dans chaque departement\n");
  printf("3-Afficher les etudiants ayant une moyenne generale superieur a un cretaine seuil\n");
  printf("4-Afficher les 3 etudiants ayant les meilleures notes\n");
  printf("5-Afficher le nombre d'etudiants ayant reussi dans chaque departement\n");
  printf("Annuler");
  printf("Votre Choix:");
  scanf("%d", &choix);
  switch(choix){
     do{
        case 1:
          afficher_totale_etudiant();
          break;
        case 2:
          nombre_etudiant_dans_departement();
          break;
        case 3:
          etudiants_superieur_a_certain_seuil();
          break;
        case 4:
          les_trois_meilleures_notes();
          break;
        case 5:
          nombre_etudiants_reussi_departement();
          break;
    }while(choix != 6);
}
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
    int choix;
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

    printf("Tu veux afficher Le nombre des etudiant dans le departement:\n");
    printf("1-Math\n");
    printf("2-Physique\n");
    printf("3-Chimie\n");
    printf("4-Informatique\n");
    printf("5-Biologie\n");
    printf("\n");
    do{
    printf("Votre Choix: ");
    scanf("%d", &choix);
    printf("\n");
        switch(choix){
            case 1:
              printf("Le nombre des etudiant dans le departement Math: %d\n", nombre_math);
             break;
            case 2:
              printf("Le nombre des etudiant dans le departement physique: %d\n", nombre_physique);
             break;
            case 3:
              printf("Le nombre des etudiant dans le departement Chimie: %d\n", nombre_chimie);
             break;
            case 4:
              printf("Le nombre des etudiant dans le departement Informatique: %d\n", nombre_info);
             break;
            case 5:
              printf("Le nombre des etudiant dans le departement biologie: %d\n", nombre_biologie);
             break;
        }
    }while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5);
    
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

    for (int i = 0; i < nombre_etudiants; i++){
        if (max1 == etudiants[i].note_generale){
            printf("\nPremier note: \n");
            printf("ID: %d\n", etudiants[i].id);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note Glbale: %.2f\n", etudiants[i].note_generale);
            printf("\n");

        }else if (max2 == etudiants[i].note_generale){
            printf("\nDeuxieme note:\n");
            printf("ID: %d\n", etudiants[i].id);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note Glbale: %.2f\n", etudiants[i].note_generale);
            printf("\n");
        }else if (max3 == etudiants[i].note_generale){
            printf("\nTroisieme note: \n");
            printf("ID: %d\n", etudiants[i].id);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note Glbale: %.2f\n", etudiants[i].note_generale);
            printf("\n");
        }
    }

}

void nombre_etudiants_reussi_departement(){
    int nombre_math = 0;
    int nombre_physique = 0;
    int nombre_chimie = 0;
    int nombre_info = 0;
    int nombre_biologie = 0;
    int choix;
    for (int i = 0; i < nombre_etudiants; i++){
        if(strcmp(etudiants[i].departement, "math") == 0 && etudiants[i].note_generale >= 10){
            nombre_math++;
        }
        if(strcmp(etudiants[i].departement, "physique")  == 0 && etudiants[i].note_generale >= 10){
            nombre_physique++;
        }
        if(strcmp(etudiants[i].departement, "chimie")  == 0 && etudiants[i].note_generale >= 10){
            nombre_chimie++;
        }
        if(strcmp(etudiants[i].departement, "informatique")  == 0 && etudiants[i].note_generale >= 10){
            nombre_info++;
        }
        if(strcmp(etudiants[i].departement, "biologie")  == 0 && etudiants[i].note_generale >= 10){
            nombre_biologie++;
        }
    }

    printf("Tu veux afficher Le nombre des etudiant qui ont reussi dans le departement:\n");
    printf("1-Math\n");
    printf("2-Physique\n");
    printf("3-Chimie\n");
    printf("4-Informatique\n");
    printf("5-Biologie\n");
    printf("\n");
    do{
    printf("Votre Choix: ");
    scanf("%d", &choix);
    printf("\n");
        switch(choix){
            case 1:
              printf("Le nombre des etudiant qui ont reussi dans le departement Math: %d\n", nombre_math);
             break;
            case 2:
              printf("Le nombre des etudiant qui ont reussi dans le departement physique: %d\n", nombre_physique);
             break;
            case 3:
              printf("Le nombre des etudiant qui ont reussi dans le departement Chimie: %d\n", nombre_chimie);
             break;
            case 4:
              printf("Le nombre des etudiant qui ont reussi dans le departement Informatique: %d\n", nombre_info);
             break;
            case 5:
              printf("Le nombre des etudiant qui ont reussi dans le departement biologie: %d\n", nombre_biologie);
             break;
        }
    }while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5);
    
}

void rechercher_un_etudiant(){
    int choix;
    printf("Tu veux rechercher par\n1-Nom\n2-departement\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    if(choix == 1){
        char nom_saisez[50];
        char nom_saisez_converter[50];
        printf("Sasiez Le Nom: ");
        scanf("%s", &nom_saisez);
        strcpy(nom_saisez_converter, strlwr(nom_saisez));
        for (int i = 0; i < nombre_etudiants; i++){
            strcpy(etudiants[i].nom, strlwr(etudiants[i].nom));
            if(strcmp(etudiants[i].nom, nom_saisez_converter)== 0){
                printf("\n");
                printf("ID: %d\n", etudiants[i].id);
                printf("Nom: %s\n", etudiants[i].nom);
                printf("Prenom: %s\n", etudiants[i].prenom);
                printf("Date de naissance: %d-%d-%d\n", etudiants[i].date_de_naissances.jour, etudiants[i].date_de_naissances.mois, etudiants[i].date_de_naissances.annee);
                printf("Departement: %s\n", etudiants[i].departement);
                printf("Note generale: %.2f\n", etudiants[i].note_generale);
            }
        }
    }else if(choix == 2){
        char choix_departement[50];
        printf("Saisez Le departement: ");
        scanf("%s", &choix_departement);
        strcpy(choix_departement, strlwr(choix_departement));
        

        for(int i = 0; i < nombre_etudiants; i++){
            strcpy(etudiants[i].departement, strlwr(etudiants[i].departement));
            if( strcmp(choix_departement, etudiants[i].departement) == 0){
                printf("\n");
                printf("ID: %d\n", etudiants[i].id);
                printf("Nom: %s\n", etudiants[i].nom);
                printf("Prenom: %s\n", etudiants[i].prenom);
                printf("Date de naissance: %d-%d-%d\n", etudiants[i].date_de_naissances.jour, etudiants[i].date_de_naissances.mois, etudiants[i].date_de_naissances.annee);
                printf("Departement: %s\n", etudiants[i].departement);
                printf("Note generale: %.2f\n", etudiants[i].note_generale);
            }
        }
    }
    
}

void triage(){
    int choix;
    printf("Trier par:\n1. Nom (A-Z)\n2. Nom (Z-A)\n3. Note generale (croissant)\n4. Note generale (décroissant)\n5. Statut de reussite\n");
    printf("Votre Choix: ");
    scanf("%d", &choix);
    switch(choix){
        case 1:
           trier_etudtiant_fct_nom();
           break;
    }
}

void trier_etudtiant_fct_nom(){
    for (int i = 0; i < nombre_etudiants; i++){
        strcpy(etudiants[i].nom, strlwr(etudiants[i].nom));
    }
   for (int i = 0; i < nombre_etudiants; i++) {
                for (int j = i + 1; j < nombre_etudiants; j++) {
                    if (strcmp(etudiants[i].nom, etudiants[j].nom) > 0) {
                        Etudiant change = etudiants[i];
                        etudiants[i] = etudiants[j];
                        etudiants[j] = change;
                    }
                }
            }
}