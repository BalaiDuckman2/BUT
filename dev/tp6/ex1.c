#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
void division(int a, int b, int *quotien, int *reste);

int main(){
   //déclaration des variables
    int chiffre1;
    int chiffre2;
    int quotient1;
    int reste1;

   // saisie des données
    printf("donner un chiffre");
    scanf("%d",&chiffre1);
    printf("donner un chiffre");
    scanf("%d",&chiffre2);
    while (chiffre2 == 0)
    {
        printf("division pas 0");
        printf("donner un chiffre");
        scanf("%d",&chiffre2);
    }
    
   // traitement des données
    division(chiffre1,chiffre2,&quotient1,&reste1);
    printf("quotient : %d \n reste : %d",quotient1,reste1);

   // affichage des résultats



   return EXIT_SUCCESS;
}

void division(int a, int b, int *quotien, int *reste){
    *quotien = a / b;
    *reste = a%b;
}
