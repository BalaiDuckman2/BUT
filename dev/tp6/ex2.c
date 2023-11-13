#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
void valeur(int *petit, int *grand);

int main(){
   //déclaration des variables
    int mini;
    int moinsmini;
   // saisie des données
    
    valeur(&mini,&moinsmini);
    printf("petit : %d",mini);
    printf("\ngrand : %d",moinsmini);

   // affichage des résultats



   return EXIT_SUCCESS;
}

void valeur(int *petit, int *grand){
    int valeur;
    
    printf("quelle valeur");
    scanf("%d",&valeur);
    *petit = valeur;
    *grand = valeur;
    while (valeur != 0)
    {
        if (valeur < 0)
        {
            printf("valeur inféérieur à 0");
        }
        else{
            if(valeur < *petit){
                *petit = valeur;
            }
            if (valeur > *grand)
            {
                *grand = valeur;
            }
        }
        printf("quelle valeur");
        scanf("%d",&valeur);
    }
    
}
