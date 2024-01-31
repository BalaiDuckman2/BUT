#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes


int main(){
   //déclaration des variables
    int nbBoucle;
    int nbValeur;
    float moyenne;
    int valeur;

   // saisie des données
    nbBoucle = 0;
    printf("combien de valeur\n");
    scanf("%d",&nbValeur);


   // traitement des données
    if(nbValeur==0){
        printf("division pas 0");

    }
    else{
        while(nbValeur!=nbBoucle){
            printf("valeur ? \n");
            scanf("%d",&valeur);
            
            moyenne= moyenne+valeur;
            nbBoucle=nbBoucle+1;


        }
        moyenne= moyenne/(nbValeur*1.0);
    }


   // affichage des résultats
    printf("moyenne: %.2f",moyenne);


   return EXIT_SUCCESS;
}