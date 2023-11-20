#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAILLE 9

//déclaration des constantes
typedef int tGrille[TAILLE][TAILLE];

void chargerGrille(tGrille grille);
void affichegrille(tGrille grille);

int main(){
   tGrille grille1;
   int numLigne, numColonne, valeur;
   //déclaration des variables
   //chargerGrille(grille1);
   //affichegrille(grille1);
   saisir(valeur);


   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}




void chargerGrille(tGrille grille){
   char nomFichier[30];
   FILE * f;
   printf("Nom du fichier ? ");
   scanf("%s", nomFichier);
   f = fopen(nomFichier, "rb");
   if (f==NULL)
   {
      printf("\n ERREUR sur le fichier %s\n", nomFichier);
   } 
   else 
   {
      fread(grille, sizeof(int), TAILLE*TAILLE, f);
   }
   fclose(f);
}   

void affichegrille(tGrille grille){
   int nombre =1;
   printf("    1  2  3   4  5  6   7  8  9\n");
   printf("  +---------+---------+---------+");

   for(int ligne=0; ligne<=8; ligne++){
      printf("\n%d |",ligne+1);
      for(int collone=0; collone <=8;collone++){
         if(grille[ligne][collone]==0){
            printf(" . ");
         }else{
            printf(" %d ",grille[ligne][collone]);
         }
         if(collone==2 || collone ==5){
            printf("|");
         }   
      }
      printf("|");
      if(ligne==2 || ligne ==5){
            printf("\n  +---------+---------+---------+");
         }

   }
   printf("\n  +---------+---------+---------+\n");

}

void saisir(int S){
   char ch;
   int x;
   scanf("%s", ch);
   if (sscanf(ch, "%d", &x)!=0){
      printf("%d",x);
   }else{
      printf("échoué");
   }
}