#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//déclaration des constantes



float fcalcul(int v1, int v2);

int main(){
   //déclaration des variables
   float resultat;
   resultat=fcalcul(1,6);

   // saisie des données
   printf("%2f",resultat);


   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

float fcalcul(int v1, int v2){
   float resultat;
   resultat = (v1*v1)+(v2*v2);
   resultat =sqrtf(resultat);
   return resultat;
}
