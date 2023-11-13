#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//déclaration des constantes
int generer(int borne);
int comparer(int valeur, int nbaleatoire);
int jeu(int resultat);
char afficherResultat(int nbcoup);
int aleaInfBorne(int borne);

int main(){
   //déclaration des variables
    int borne;
    printf("max");
    scanf("%d",&borne);
    afficherResultat(jeu(aleaInfBorne(borne)));
    
   // saisie des données


   // affichage des résultats


   return EXIT_SUCCESS;
}

int aleaInfBorne(int borne){
    srand(time(NULL));
    return rand() % borne;
}

int comparer(int valeur, int nbaleatoire){
    if(valeur < nbaleatoire){
        return -1;
    }
    if(valeur > nbaleatoire){
        return 1;
    }
    if (valeur == nbaleatoire)
    {
        return 0;
    }
   return EXIT_SUCCESS;
}

int jeu(int secret){
    int compteur;
    int nombre;
    nombre = -1;
    compteur = 0;
    while (nombre !=secret)
    {
        compteur = compteur +1;
        printf("quelle valeur \n");
        scanf("%d",&nombre);
        
        if(secret > nombre)
        {
            printf("trop petit \n");
        }
        if (secret < nombre)
        {
            printf("trop grand \n");
              

        }
        if(secret == nombre){
            
            return compteur;
        }
        if(compteur == 10){
            return 11;
        }

    }  
    return EXIT_SUCCESS;

     
}

char afficherResultat(int nbcoup){
    if(nbcoup == 11){
        printf("perdu");
        return 'P';
    }else{
        printf("Gagner en %d",nbcoup);
        return 'G';
    }
    return EXIT_SUCCESS;

}
