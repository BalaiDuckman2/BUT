#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//déclaration des constantes
int factorielle(int v1);

int main(){
   //déclaration des variables



   // saisie des données

    printf("%d",factorielle(7));

   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

int factorielle(int v1){
    int totale;
    totale = 1;
    while(v1!=0){
        totale = totale *v1;
        v1 = v1-1;
    }
    return(totale);
}
