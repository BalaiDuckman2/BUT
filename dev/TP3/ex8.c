#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes


int main(){
   //déclaration des variables
    int premier; 
    int nombre;
    int compteur;
   // saisie des données
    premier = 0;
    compteur = 1;
    printf("rentrer un nombre");
    scanf("%d",&nombre);
   // traitement des données
    while(compteur != nombre ){
        premier = nombre/compteur;
        compteur = compteur+1;
        
    }
    
    if(premier ==1){
        printf("le nombre est un chiffre premier");

    }else{
        printf("le chiffre n'est pas un chiffre premier");
    }

   // affichage des résultats



   return EXIT_SUCCESS;
}