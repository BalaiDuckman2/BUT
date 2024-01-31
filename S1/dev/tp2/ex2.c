#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
const float KWH1 = 10.0;
const float KWH2 = 15.0;
const float KWH3 = 20.0;
const float TVA = 1.20;
const float COUP = 1500.0;
const float PKWH2 = 100.0;
const float PKWH3 = 50.0;
int main(){
   //déclaration des variables
    float consomme ;
    float prix;
    float rkwh2;
    float rkwh3;



   // saisie des données
    printf("quantité consommée");
    scanf("%f",&consomme);


   // traitement des données
    if(consomme<100){
        
        prix=KWH1*consomme;
        prix=prix+COUP;
        prix= prix*TVA;

    
    }else if(consomme>150){
        rkwh2 = consomme-PKWH2;
        prix = ((PKWH2*10)+(rkwh2*15)+COUP)*TVA;


    }else{
        
        rkwh3 = consomme-(PKWH3+PKWH2);
        prix = ((PKWH2*10)+(PKWH3*15)+(rkwh3*15)+COUP)*TVA;  

    }




   // affichage des résultats
    printf("%f",prix);


   return EXIT_SUCCESS;
}