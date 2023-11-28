#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//déclaration des constantes
#define N 10
#define I 20
typedef int tab2dim[N][I];
void initialiser(tab2dim tab);
void afficher(tab2dim tab);
bool existe(tab2dim tab, int valeur);
int main(){
   //déclaration des variables
    tab2dim tab;
    int oui;
    initialiser(tab);
    afficher(tab);
    oui = existe(tab, 30);
    if(oui == true){
        printf("oui");
    }
    else{
        printf("non");
    }
   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}
void initialiser(tab2dim tab){
    for(int i=0;i<N;i++){
        for (int j = 0; j < I; j++)
        {
            tab[i][j]=i+j;
        }
        
    }
}
void afficher(tab2dim tab){
    for(int i=0;i<N;i++){
        for (int j = 0; j < I; j++)
        {
            printf("%3d ",tab[i][j]);
        }
        printf("\n");
    }
}
bool existe(tab2dim tab, int valeur){
    bool fin=false;
    int i =0;
    int j=0;
    while (fin == false && i<N)
    {
        while (fin == false && j<I)
        {
            if(tab[i][j]==valeur){
                fin = true;
            }
            j++;
        }
        j=0;
        i++;
    }
    return fin;
}