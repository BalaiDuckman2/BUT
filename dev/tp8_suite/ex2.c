#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//déclaration des constantes
#define N 10
typedef int tab[N];


void tri_selection(tab t);

int main(){
   //déclaration des variables
    tab tableau = {9,5,7,4,1,2,0,8,6,3};
    tri_selection(tableau);
    for(int i=0;i<N;i++){
        printf("%d ",tableau[i]);
    }
   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void tri_selection(tab t){
    int conteneur;
    for(int i=0; i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(t[i]>t[j]){
                conteneur=t[i];
                t[i]=t[j];
                t[j]=conteneur;
            }
        }
    }
}
