#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//déclaration des constantes
int aleaInfBorne(int borne);

int main(){
   //déclaration des variables
   srand(time(NULL));


   // saisie des données


   // affichage des résultats
   printf("%d",aleaInfBorne(100));


   return EXIT_SUCCESS;
}

int aleaInfBorne(int borne){
   return rand() % borne;
}