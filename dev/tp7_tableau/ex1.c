#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
#define N 5
typedef int unTableau[N];
int somme(unTableau tablo);
int main(){
   //déclaration des variables
    unTableau monTableau= {5,8,2,3,4};
    int oui;

   // saisie des données
    oui = somme(monTableau);
    printf("%d",oui);

   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}


int somme(unTableau tablo){
    int resultat;
    resultat = 0;
    for (int i = 0; i < N; i++)
    {
        resultat = resultat + tablo[i];
    }
    return resultat;
    

}