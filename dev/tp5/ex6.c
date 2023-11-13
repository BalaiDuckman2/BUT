#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes

void ligneTirets(int n);
void ligneCourante(int n);


int main(){
   //déclaration des variables
    int hauteur;


   // saisie des données
    printf("hauteur");
    scanf("%d", &hauteur);
    while (hauteur >50 || hauteur<3)
    {
        printf("hauteur ?");
        scanf("%d", &hauteur);
    } 


   // traitement des données
    ligneCourante(hauteur);
    ligneTirets(hauteur);
    return EXIT_SUCCESS;

   // affichage des résultats



   return EXIT_SUCCESS;
}

void ligneCourante(int n){
    int espace;
    int i;
    espace=1;
    i =1;
    while(n!=0)
    {
        printf("I");
        while(espace!=1)
        {
            printf(" ");
            espace = espace-1;
        }
        printf("\\");
        printf("\n");
        i = i +1;
        espace =i;
        n = n-1;
    }
    
}
void ligneTirets(int n){
    n = n+1;
    while (n!=0)
    {
        printf("-");
        n = n-1;
    }
    
}
