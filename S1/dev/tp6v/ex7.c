#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//déclaration des constantes
const char PIERRE = 'P';
const char FEUILLE = 'F';
const char CISEAUX = 'C';


char verifier(char action1, char action2);
char bot();
char jouer();

int main(){
   //déclaration des variables



   // saisie des données
    printf("%c",jouer());


   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

char verifier(char action1, char action2){
    if (action1 == action2)
    {
        printf("égalité\n");
    }
    if(action1 == PIERRE && action2 == CISEAUX) {
        return 'G';
    }
    if(action1 == PIERRE && action2 == FEUILLE) {
        return 'F';
    }
    if(action1 == CISEAUX && action2 == PIERRE) {
        return 'F';
    }
    if(action1 == CISEAUX && action2 == FEUILLE) {
        return 'G';
    }
    if(action1 == FEUILLE && action2 == CISEAUX) {
        return 'F';
    }
    if(action1 == FEUILLE && action2 == PIERRE) {
        return 'G';
    }
    return EXIT_FAILURE;
    
}

char bot(){
    int choix;
    srand(time(NULL));
    choix = rand() % 2;
    if(choix==0){
        return 'P';
    }
    if (choix==1)
    {
        return 'F';
    }
    if (choix==2)
    {
        return 'C';
    }
    
    return EXIT_FAILURE;
}

char jouer(){
    char valeur;
    char poubelle;
    char resultat;
    int pointH;
    int pointR;
    pointH =0;
    pointR =0;
    while (pointH !=3 && pointR != 3)
    {
        printf("Pierre feuille ciseaux (P,F,C)\n");
        scanf("%c%c",&valeur,&poubelle);
        resultat = verifier(valeur,bot());
        if(resultat == 'G'){
            pointH = pointH+1;
            printf("bien\n");
        }
        if(resultat=='F'){
            pointR = pointR+1;
            printf("pas bien\n");

        }
    }
    if (pointH==3)
    {
        return 'H';
    }
    if (pointR == 3)
    {
        return 'B';
    }
    return EXIT_FAILURE;
    
}