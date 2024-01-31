#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
const float GENERAL = 10;
const float MOYENNE_UE = 8;



int main(){
   //déclaration des variables
    float ue1;
    float ue2;
    float moyenneg;

   // saisie des données
   printf("UE1\n");
   scanf("%f",&ue1);
   printf("UE2\n");
   scanf("%f",&ue2);


   // traitement des données
   
   moyenneg= (ue1+ue2)/2;
   
   if(moyenneg<10){
      printf("Jury souverain");


   }else if(ue1<8){
      printf("Redoublement");


   }else if(ue2<8){
      printf("Redoublement");


   }else
      printf("Semestre validé");

   // affichage des résultats



   return EXIT_SUCCESS;
}