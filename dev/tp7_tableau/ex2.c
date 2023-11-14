#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
#define N 5
typedef int vecteur[N];
void remplirVecteur (vecteur v);
void afficherVecteur (vecteur v);
void sommeVecteur (vecteur v1, vecteur v2, vecteur vSomme);

int main(){
   //déclaration des variables
    vecteur v1;
    vecteur v2;
    vecteur vSomme;
    remplirVecteur(v1);
    afficherVecteur(v1);
    remplirVecteur(v2);
    afficherVecteur(v2);
    sommeVecteur(v1,v2,vSomme);


   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void remplirVecteur (vecteur v){
    for (int i = 0; i < N; i++)
    {
        printf("valeur");
        scanf("%d",&v[i]);
    }
    

}
void afficherVecteur (vecteur v){
    for (int i = 0; i < N; i++)
    {
        printf("%d\n",v[i]);
    }
    
}
 
void sommeVecteur (vecteur v1, vecteur v2, vecteur vSomme){
    printf("\nrésulat\n");
    for (int i = 0; i < N; i++)
    {
        vSomme[i]=v1[i]+v2[i];
        printf("%d\n",vSomme[i]);
    }
    
}
