#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
//déclaration des constantes


int main(){
   //déclaration des variables
    float valeur;
    float grandeValeur;
    float nbValeur;
    float compte;
   // saisie des données
    grandeValeur = INT_MIN;
    compte = 0;
    printf("saisir le nombre de valeur \n");
    scanf("%f",&nbValeur);




   // traitement des données
    while(compte!=nbValeur){
        printf("saisir le nombre une valeur\n");
        scanf("%f",&valeur);
        if(grandeValeur<valeur){
            grandeValeur = valeur;
        }
        compte=compte+1;
    }


   // affichage des résultats
    printf("la plus grande valeur est: %.2f",grandeValeur);


   return EXIT_SUCCESS;
}