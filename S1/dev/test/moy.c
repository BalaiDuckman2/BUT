#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes

const int FIN = -1;
int main(){
   //déclaration des variables
    int moy;
    int n;
    int valeur;
    n =0;
    
    printf("quelle valeur");
    scanf("%d",&valeur);
    
   // saisie des données
    while(valeur !=FIN){
      moy = moy +valeur;
      n = n+1;

    }
   if(n ==0){
      printf("il n'y a pas de valeur")
   }

   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}