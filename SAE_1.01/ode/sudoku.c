#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAILLE 9

//déclaration des constantes
typedef int tGrille[TAILLE][TAILLE];

void chargerGrille(tGrille g);
void affichegrille(tGrille g);

int main(){
   tGrille grille1;
   int numLigne, numColonne, valeur;
   //déclaration des variables
   chargerGrille(grille1);
   affichegrille(grille1);


   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}




void chargerGrille(tGrille g){
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
      fread(g, sizeof(int), TAILLE*TAILLE, f);
   }
   fclose(f);
}   

void affichegrille(tGrille g){
   int nombre =1;
   printf("    1  2  3   4  5  6   7  8  9\n");
   for(int i =0; i<=2; i++){
      printf("  +---------+---------+---------+\n");
      for (int e = 0; e <=2 ; e++)
      {
         printf("%d | .  .  . | .  .  . | .  .  . |\n",nombre);
         nombre = nombre+1;
      }
      
   } 
   printf("  +---------+---------+---------+\n");

}
