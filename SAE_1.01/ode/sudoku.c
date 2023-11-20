#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAILLE 9

//déclaration des constantes
typedef int tGrille[TAILLE][TAILLE];

void chargerGrille(tGrille grille);
void affichegrille(tGrille grille);
void saisir(int *valeur);
int possible(tGrille grille,int ligne,int colonne,int valeur);

int main(){
   tGrille grille1;
   int numLigne, numColonne, valeur,oui,pos;
   oui=0;
   chargerGrille(grille1);
   //déclaration des variables
   while (oui==0)
   {
      affichegrille(grille1);
      saisir(&numLigne);
      saisir(&numColonne);
      saisir(&valeur);
      pos=possible(grille1, numLigne, numColonne, valeur);
      if(pos==1){
         grille1[numLigne-1][numColonne-1] = valeur;
      }else{
         printf("valeur déjà mise\n");
      }
   }
   
   
   

   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}




void chargerGrille(tGrille grille){
   char nomFichier[30];
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

void saisir(int *valeur){
   char ch[10];
   int x=0;
   int fin=0;
   while(fin==0){
      printf("saisir un chiffre:\n");
      scanf("%s", ch);
      if (sscanf(ch, "%d", &x)!=0)
      {
         if(x<1 || x>9){
            printf("saisir un chiffre entre 1 et 9\n");
         }
         else{
            *valeur = x;
            fin=1;
         }
      }
      else{
         printf("erreur ce n'est pas un chiffre \n");
      }
   }
}

int possible(tGrille grille,int ligne,int colonne,int valeur){
   int prise =1;
   for(int i =0; i<=8; i++){
      if(valeur == grille[ligne-1][i]){
         printf("1\n");
         return 0;
      }
      if(valeur== grille[i][colonne-1]){
         printf("2\n");
         return 0;
      }
   }
   for(int i=3; i<=9; i=i+3){
      for (int j = 3; j < 9; j=j+3)
      {  
         if (ligne < i && colonne < j)
         {
            for (i < i-2 ; i=i-1;)
            {
               for (j < j-2; j=j-2;)
               {
                  if (valeur==grille[i][j])
                  {
                     printf("3\n");
                     return 0;
                  }else{
                     return 1;
                  }
               }
            }
         }
         
      }
   }   
}