#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//déclaration des constantes
#define N 4
#define TAILLE (N*N) 
#define TAILLE_TOUT (TAILLE*TAILLE)

const int TAILLE_FICHIER = 30;
const int DEBUT = 0;



//déclaration du type tGrille 
typedef int tGrille[TAILLE][TAILLE];

void chargerGrille(tGrille grille);
void affichegrille(tGrille grille);

bool possible(tGrille grille,int ligne,int colonne,int valeur);
bool grilleComplete(tGrille grille);
bool backtracking(tGrille grille, int numeroCase);

int main(){
  
   tGrille grille1;
   int numLigne, numColonne, valeur;
   
   chargerGrille(grille1);
   affichegrille(grille1);
   clock_t begin = clock();
   srand(time(NULL));
   backtracking(grille1,0);
   clock_t end = clock();
   double  tmpsCPU = (end - begin)*1.0 / CLOCKS_PER_SEC;
   affichegrille(grille1);
   printf( "Temps CPU = %.3f secondes\n",tmpsCPU);
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
   
   printf("  +--------------------+--------------------+--------------------+--------------------+\n  |");

   for(int ligne=DEBUT; ligne<TAILLE; ligne++){
      
      for(int collone=DEBUT; collone <TAILLE;collone++){
         if(grille[ligne][collone]==0){
            printf("  .  ");
         }else{
            printf(" %3d ",grille[ligne][collone]);
         }
         if(collone==3 || collone ==7||collone==11){
            printf("|");
         }   
      }
      printf("|");
      if (ligne!=15&& ligne !=7 && ligne!=11&&ligne!=3)
      {
         printf("\n  |");
      }
      
      if(ligne==3 || ligne ==7 || ligne==11){
            printf("\n  +--------------------+--------------------+--------------------+--------------------+\n  |");
         }
      
   }
   printf("\n  +--------------------+--------------------+--------------------+--------------------+\n");

}



bool possible(tGrille grille, int ligne, int colonne, int valeur) {
    bool fin = true;
    int i, j, recupi, recupj;
    bool finboucle = false;

    i = DEBUT;
    while (fin == true && i < TAILLE) {
        if (valeur == grille[ligne][i] || valeur == grille[i][colonne]) {
            fin = false;
        }
        i++;
    }
    
    if (fin == true) {
        i = N;
        while (finboucle == false && i <= TAILLE) {
            j = N;
            while (finboucle == false && j <= TAILLE) {
                if (ligne < i && colonne < j) {
                    recupi = i;
                    while (finboucle == false && i >= recupi - 3) {
                        recupj = j;
                        while (finboucle == false && j >= recupj - 3) {
                            if (valeur == grille[i - 1][j - 1]) {
                                fin = false;
                                finboucle = true;
                            }
                            j = j - 1;
                        }
                        j = recupj;
                        i = i - 1;
                    }
                    finboucle = true;
                }
                j = j + N;
            }
            i = i + N;
        }
    }
    return fin;
}

bool grilleComplete(tGrille grille){
   bool fin = true;
   int ligne=DEBUT;
   int collone=DEBUT;
   while(ligne<=TAILLE && fin == true)
   {
      while(collone<=TAILLE && fin == true)
      {
         if(grille[ligne][collone]==0)
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

bool backtracking(tGrille grille, int numeroCase){
   int ligne=0,colonne=0;
   bool resultat=false;
   if (numeroCase == TAILLE*TAILLE)
   {
      resultat=true;
   }else{
      ligne=numeroCase/TAILLE;
      colonne=numeroCase%TAILLE;
      if (grille[ligne][colonne]!=0)
      {
         resultat= backtracking(grille,numeroCase+1);
      }else{
         for (int valeur = 1; valeur <= TAILLE; valeur++)
         {
            if (possible(grille,ligne,colonne,valeur))
            {
               grille[ligne][colonne]=valeur;
               if (backtracking(grille,numeroCase+1)==true)
               {
                  resultat=true;
               }else{
                  grille[ligne][colonne]=0;
               }
               
            }
            
         }
         
      }
      
   }
   return resultat;
   
}