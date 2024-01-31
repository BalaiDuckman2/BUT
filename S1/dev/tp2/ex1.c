
#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
const float ekilometre = 1.2;
const float ejourné = 10;
const float dkilometre = 1.0;
const float djourné = 15;
int main(){
   //déclaration des variables
    float kilometre, journé, eprix, dprix;


   // saisie des données
    printf("kilometre \n");
    scanf("%f",&kilometre);
    printf("journé \n");
    scanf("%f",&journé);
    // traitement des données
    eprix= (ejourné*journé)+(ekilometre*kilometre);
    dprix= (djourné*journé)+(dkilometre*kilometre);
    
    
   // affichage des résultats
    if(eprix==dprix){
        printf("égalité");
    } else if(eprix<dprix){
        printf("véhicule essence moins coûteux");

    }else{
        printf("véhicule diesel moins coûteux");

    }





   return EXIT_SUCCESS;
}