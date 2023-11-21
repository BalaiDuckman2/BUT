#include <stdlib.h>
#include <stdio.h>
#define N 10
typedef int tabEntiers[N];
int recherche_dicho_iteratif(int valeur,  tabEntiers tablo);
int recherche_dicho_recursif(int valeur, tabEntiers tablo, int debut, int fin);


//déclaration des constantes


int main(){
   //déclaration des variables
    tabEntiers  leTabloTrie = {13, 24, 35, 42, 53, 68, 77, 83, 88, 91} ;
    printf("%d",recherche_dicho_recursif(91,  leTabloTrie,0,N-1));

   // saisie des donnée


   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}




int recherche_dicho_iteratif(int valeur,  tabEntiers tablo){
    int max = N-1;
    int min = 0;
    int i;
    i = (max+min)/2;
    while (min < max && valeur != tablo[i])
    {
        
        if(valeur < tablo[i]){
            max = i-1; 
        }
        
        if(valeur > tablo[i]){
            min = i+1;
        }
        i = (max+min)/2;     
    }

    if (valeur == tablo[i])
    {
        return i;    
    }else{
        return -1;
    }
    
 
    
}

int recherche_dicho_recursif(int valeur, tabEntiers tablo, int debut, int fin){
    if (debut <= fin) {
        int i = (debut + fin) / 2;
        if(tablo[i] == valeur) {
            return i;
        }
        if (tablo[i] > valeur) {
            return recherche_dicho_recursif(valeur, tablo, debut, i-1);
        }
        if(tablo[i]< valeur){
            return recherche_dicho_recursif(valeur, tablo, i+1, fin);
        }
    }   

    return -1;
}
