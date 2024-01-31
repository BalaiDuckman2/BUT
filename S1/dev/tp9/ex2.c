#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//déclaration des constantes
#define N 10
typedef float t_vecteur[N];
typedef float t_matrice[N][N];
void afficherVecteur(t_vecteur vect,int nb);
void afficherMatrice(t_matrice mEvolution, int nb);
void   produitVectMat(t_vecteur   vInitial,   t_matrice   mEvolution,t_vecteur vResultat, int nb);
void copiervecteur(t_vecteur   vInitial,t_vecteur vResultat,int nb);
int main(){
   //déclaration des variables
   t_vecteur vecteur = {35,25,20,20};
   t_vecteur vecteur1;
   t_matrice matrice = {{0.9,0.06,0.08,0.05},{0.03,0.8,0.02,0.03},{0.02,0.03,0.75,0.04},{0.05,0.11,0.15,0.88}};
   for (int i = 0; i < 30; i++)
   {
      produitVectMat(vecteur,matrice,vecteur1,4);
      copiervecteur(vecteur,vecteur1,4);  
   }
   
   
   for (int i = 0; i < 4; i++)
   {
      printf(" %.2f ",vecteur1[i]);
   }
   
   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}
void afficherVecteur(t_vecteur vect,int nb){
   for(int i=0;i<nb;i++){
      printf("%.0f ",vect[i]);
   }
   printf("\n\n");
}

void afficherMatrice(t_matrice mEvolution, int nb){
   for(int i=0;i<nb;i++){
      for (int j = 0; j < nb; j++)
      {
         printf(" %.2f ",mEvolution[i][j]);
      }
      printf("\n");
   }
}

void   produitVectMat(t_vecteur   vInitial,   t_matrice   mEvolution,t_vecteur vResultat, int nb){
   for (int i = 0; i < nb; i++)
   {
      vResultat[i]=0;
      for (int j = 0; j < nb; j++)
      {
         vResultat[i] = vResultat[i]+(vInitial[j]*mEvolution[i][j]);
      }
      
   }
   
}

void copiervecteur(t_vecteur   vInitial,t_vecteur vResultat,int nb){
   int stock;
   for (int i = 0; i < nb; i++)
   {
      vInitial[i]=vResultat[i];
   }
   
}