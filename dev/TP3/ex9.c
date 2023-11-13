#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes


int main(){
   //déclaration des variables
    int nombre;
    int compteur;
    int carré;
    int exposant;
   // saisie des données
    compteur = 0;
    printf("rentrer un nombre");
    scanf("%d",&nombre);
    printf("rentrer un exposant");
    scanf("%d",&exposant);
    carré = nombre;
   // traitement des données
    while(compteur != exposant){
        carré = carré * nombre;
        compteur = compteur +1;
    }


   // affichage des résultats
    printf("%d",carré);


   return EXIT_SUCCESS;
}