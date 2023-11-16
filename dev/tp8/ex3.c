#include <stdlib.h>
#include <stdio.h>
#define N 8
typedef char mot8lettres[N];
void init(mot8lettres tablo);
void saisir(mot8lettres tablo);
//déclaration des constantes


int main(){
   //déclaration des variables
    mot8lettres tab;
    init(tab);
    saisir(tab);


   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void init(mot8lettres tablo){
    for(int i = 0; i < N; i++)
    {
        tablo[i] = '*';
    }
    
}

void saisir(mot8lettres tablo){
    for(int i = 0; i < N; i++)
    {
        scanf("%c",tablo[i]);
    }
    printf("%c",tablo);
}

