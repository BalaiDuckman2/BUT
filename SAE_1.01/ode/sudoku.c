#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//déclaration des constantes
const int TAILLE_FICHIER = 30;
const int N = 3;
const int DEBUT = 0;
#define TAILLE 9

//déclaration du type tGrille 
typedef int tGrille[TAILLE][TAILLE];

void chargerGrille(tGrille grille);
void affichegrille(tGrille grille);
void saisir(int *valeur);
bool possible(tGrille grille,int ligne,int colonne,int valeur);
bool grilleComplete(tGrille grille);

int main(){
   tGrille grille1;
   int numLigne, numColonne, valeur;
   
   chargerGrille(grille1);
   while (grilleComplete(grille1)==false)
   {
      affichegrille(grille1);
      printf("Choix de la colonne(1-9):\n");
      saisir(&numColonne);
      printf("Choix de la ligne(1-9):\n");
      saisir(&numLigne);
      if(grille1[numLigne-1][numColonne-1]!=0){
         printf("IMPOSSIBLE, la case n'est pas libre.\n");
      }
      else
      {
         printf("Valeur à insérer(1-9):\n");
         saisir(&valeur);
         if(possible(grille1, numLigne, numColonne, valeur)==true){
            grille1[numLigne-1][numColonne-1] = valeur;
         }else{
            printf("valeur déjà mise\n");
         }
      }
   }
   printf("Grille pleine, fin de partie");
   return EXIT_SUCCESS;
}




void chargerGrille(tGrille grille){
   char nomFichier[TAILLE_FICHIER];
   FILE * f;
   printf("Nom du fichier : ");
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
   printf("    1  2  3   4  5  6   7  8  9\n");
   printf("  +---------+---------+---------+");

   for(int ligne=DEBUT; ligne<TAILLE; ligne++){
      printf("\n%d |",ligne+1);
      for(int collone=DEBUT; collone <TAILLE;collone++){
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

void saisir(int *valeur){
   char ch[10];
   float x;
   int y;
   bool fin=false;
   while(fin==false){
      scanf("%s", ch);
      if (sscanf(ch, "%f", &x)!=0)
      {
         if(x<1 || x>10){
            printf("saisir un chiffre entre 1 et 9 :\n");
         }
         else{
            y=x;
            if(x==y)
            {
               *valeur = x;
               fin=true;
            }
            else{
               printf("saisir un chiffre entre 1 et 9 sans virgule :\n");
            }
         }
      }
      else{
         printf("erreur ce n'est pas un chiffre \n");
      }
   }
}

bool possible(tGrille grille,int ligne,int colonne,int valeur){
   bool fin = true;
   int i;
   int j;
   while(i<=TAILLE){
      i=DEBUT;
      if(valeur == grille[ligne-1][i] || grille[i][colonne-1]){
         return false;
      }
      i++;
   }
   if(fin==true){
      i=N;
      j=N;
      while(fin==true && i>=N*N; ){
         while(fin == true && j >= N*N)
         {  
            if (ligne < i && colonne < j)
            {
               while (fin ==true && i!=0)
               {
                  while (fin == true && j!=0)
                  {
                     if (valeur==grille[i][j])
                     {  
                     fin = false;
                     }
                     j=j-1;
                  }
                  i=i-1;
               }
            }
            j=j+N;
         }
         i=i+N;
      }   
   }
   return fin;
}
bool grilleComplete(tGrille grille){
   for(int ligne=DEBUT; ligne<TAILLE; ligne++)
   {
      for(int collone=DEBUT; collone <TAILLE;collone++)
      {
         if(grille[ligne][collone]==0)
         {
            return false;
         }
      }
   }
   return true;
}