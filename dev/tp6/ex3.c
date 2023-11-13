#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//déclaration des constantes
const float taxe = 0.20;   
const char FIN[] ="*";
void traiterUnEmploiy(char nom[], float salBrut,float *totalSalNet);
void afficheMoyenne(int nbPersonne, float  totalSalNet);
int main(){
   //déclaration des variables
    char nom[19];
    float salaire;
    float totalNet;
    int nbPersonne;
    totalNet = 0;

   // saisie des données
    printf("Nom?\n");
    scanf("%s",nom);
    while (strcmp(nom,FIN)!=0)
    {
        printf("salaire");
        scanf("%f",&salaire);
        traiterUnEmploiy(nom,salaire,&totalNet);
        nbPersonne = nbPersonne+1;
        printf("Nom?\n");
        scanf("%s",nom);
    }
    
   // traitement des données
    afficheMoyenne(nbPersonne,totalNet);


   // affichage des résultats


   return EXIT_SUCCESS;
}

void  traiterUnEmploiy(char nom[], float salBrut,float *totalSalNet){
    float salNet;
    salNet = salBrut-(salBrut *taxe);
    *totalSalNet = salNet + *totalSalNet;
    printf("%s, salaire: %f\n",nom,salNet);

}
void afficheMoyenne(int nbPersonne, float  totalSalNet){
    float moyenne;
    if(nbPersonne == 0){
        printf("personne");
    }
    else{
        moyenne = totalSalNet/nbPersonne;
        printf("%f",moyenne);
    }
}
