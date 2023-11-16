
#include <stdlib.h>
#include <stdio.h>

#define N 10
typedef int tabEntiers[N];
int recherche_sequentielle(int valeur, tabEntiers tablo);


//déclaration des constantes


int main(){
   //déclaration des variables
    


   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

int recherche_sequentielle(int valeur, tabEntiers tablo){
    int chiffre;
    int i;
    i = 0;
    
    while(i < N && valeur != tablo[i]){
        i++;
        
       
    }
    if (valeur == tablo [i])
    {
        return i;
    }
    else{
        return -1;
    }
    
    
}