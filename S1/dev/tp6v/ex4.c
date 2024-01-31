#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//déclaration des constantes
float division(float v1,float v2);
float multiplication(float v1,float v2);
float addition(float v1,float v2);
float soustraction(float v1,float v2);

int main(){
   //déclaration des variables
   float resultat;
   

   // saisie des données
   resultat= (soustraction(addition(4.2,multiplication(5.3,addition(division(addition(4.5,1.3),2.0),1.1))),1.0));
   printf("%.2f",resultat);
   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}


float division(float v1,float v2){
   float resultat;
   resultat=v1/v2;
   return resultat;
}


float multiplication(float v1,float v2){
   float resultat;
   resultat=v1*v2;
   return resultat;
}



float addition(float v1,float v2){
   float resultat;
   resultat=v1+v2;
   return resultat;
}



float soustraction(float v1,float v2){
   float resultat;
   resultat=v1-v2;
   return resultat;
}

