#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//déclaration des constantes

#define N 5
typedef char chaine20[21];
typedef chaine20 tabnoms[N];
void affiche(tabnoms t,int n);
void maintienTrie(tabnoms t, int n);
int main(){
   //déclaration des variables
    tabnoms tNoms = {"toto","zozo","loto","momo","mimi"};
    affiche(tNoms,N);
    maintienTrie(tNoms,N);
    printf("\n");
    affiche(tNoms,N);



   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void affiche(tabnoms t,int n){
    for(int i =0; i<n;i++){
        printf("%s\n",t[i]);
    }
}

void maintienTrie(tabnoms t, int n){
    chaine20 conteneur;
    int i;
    int compteur;
    compteur = 0;

    while(compteur!=N){
        
        
        for(int i=n-1; i>=1 ;i=i-1){
            if(strcmp(t[i],t[i-1])<0){
                strcpy(conteneur,t[i]);
                strcpy(t[i],t[i-1]);
                strcpy(t[i-1],conteneur);

                
            }else{
                compteur = compteur+1;
                
            }
        }
    }
    
}