#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
#define N 9
typedef int billet[N];


const valeur[] ={500,200,100,50,20,10,5,2,1};

void initTab(billet totale);
void mjTab(int valeur);
void recap();

int main(){
   //déclaration des variables



   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void initTab(billet totale){
    for (int i = 0; i < N; i++)
    {
        totale[i]=0;
    }
    
}

void mjTab(int valeur){
    int reste;
    int compteur;
    int resultat;
    while(valeur != 0)
    {
        resultat = valeur;
        if(resultat==0){
            compteur = compteur+1;
        }
    }
    
}