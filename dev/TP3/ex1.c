#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes


int main(){
   //déclaration des variables
    int i;
    int n;
    int somme;



   // saisie des données
    printf("donne un nombre");
    scanf("%d",&n);
    i=1;
    somme=1;

   // traitement des données   
    if(n==0){
        printf("résultat: 0");

    }
    else {
        while(i<=n){
            somme=somme*i;
            i=i+1;

    }
    printf("résultat: %d\n",somme);
    }

   // affichage des résultats
    


   return EXIT_SUCCESS;
}