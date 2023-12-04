#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//déclaration des constantes
const int TAILLE_FICHIER = 30;
const int N = 3;
const int DEBUT = 0;
#define TAILLE 9
#define TAILLE_TOUT 81

//déclaration du type tGrille 
typedef struct {
   int valeur;
   int candidats[TAILLE];
   int nbCandidats;
} tCase1;

typedef tCase1 tGrille[TAILLE][TAILLE];


void chargerGrille(tGrille grille);
void affichegrille(tGrille grille);
void saisir(int *valeur);
bool possible(tGrille grille,int ligne,int colonne,int valeur);
bool grilleComplete(tGrille grille);

void ajouterCandidat(tCase1 laCase, int val);
void retirerCandidat(tCase1 laCase, int val);
bool estCandidat(tCase1 laCase, int val);
int nbCandidats(tCase1 laCase);

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
      if(grille1[numLigne-1][numColonne-1].valeur!=0){
         printf("IMPOSSIBLE, la case n'est pas libre.\n");
      }
      else
      {
         printf("Valeur à insérer(1-9):\n");
         saisir(&valeur);
         if(possible(grille1, numLigne, numColonne, valeur)==true){
            grille1[numLigne-1][numColonne-1].valeur = valeur;
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
        for(int i; i<=TAILLE_TOUT;i++){
            fread(&grille[i/TAILLE][i%TAILLE].valeur, sizeof(int), 1, f);
        }
   }
   fclose(f);
}   

void affichegrille(tGrille grille){
   printf("    1  2  3   4  5  6   7  8  9\n");
   printf("  +---------+---------+---------+");

   for(int ligne=DEBUT; ligne<TAILLE; ligne++){
      printf("\n%d |",ligne+1);
      for(int collone=DEBUT; collone <TAILLE;collone++){
         if(grille[ligne][collone].valeur==0){
            printf(" . ");
         }else{
            printf(" %d ",grille[ligne][collone].valeur);
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
   int recupi;
   int recupj;
   bool finboucle = false;

   i=DEBUT;
   while(fin ==true && i < TAILLE){
      
      if(valeur == grille[ligne-1][i].valeur || valeur == grille[i][colonne-1].valeur){
         
         fin = false;
      }
      i++;
   }
   if(fin==true)
   {
      i=N;
      while (finboucle==false && i<=8)
      {
         j = N;
         while (finboucle==false && j<=8)
         {
            if (ligne <= i && colonne <= j)
            {
               recupi = i;
               while(finboucle == false && i >= recupi-2)
               {
                  recupj = j;
                  while (finboucle==false && j >= recupj-2)
                  {
                     if (valeur==grille[i-1][j-1].valeur)
                     {
                        fin = false;
                        finboucle =true;
                        
                     }
                        j=j-1;
                     }
                     j = recupj;
                     i=i-1;
                  }
               
               finboucle = true;
            }
            j=j+N;
         }
         i=i+N;
      }

      
   }
   return fin;
}

bool grilleComplete(tGrille grille){
   bool fin = true;
   int ligne=DEBUT;
   int collone=DEBUT;
   while(ligne<TAILLE && fin == true)
   {
      while(collone<TAILLE && fin == true)
      {
         if(grille[ligne][collone].valeur==0)
         {
            fin = false;
         }
         collone++;
      }
      ligne++;
      collone=DEBUT;
   }
   return fin;
}




void ajouterCandidat(tCase1 laCase, int val){
   laCase.nbCandidats++;
   laCase.candidats[laCase.nbCandidats++] = val;
}

void retirerCandidat(tCase1 laCase, int val){
   int i = 0;
   int n = 0;
   laCase.nbCandidats = laCase.nbCandidats-1;
   while (i<= laCase.nbCandidats)
   {
      if (laCase.candidats[i]==val || n ==1)
      {
         laCase.candidats[i]=laCase.candidats[i+1];
         n=1;
      }
      i++;
   }
   
}
bool estCandidat(tCase1 laCase, int val){
   int i = 0;
   bool fin = false;
   while (i<=laCase.nbCandidats && finboucle == false)
   {
      if(val == laCase.candidats){
         fin = true;
      }
      i++;
   }
   return fin;
}
int nbCandidats(tCase1 laCase){
   return laCase.nbCandidats;
}
