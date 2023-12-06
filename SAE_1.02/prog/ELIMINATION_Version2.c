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
bool candidats[TAILLE + 1];
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
void metcandidat(tGrille tab);
void singletonNu();
void initialise(tGrille tab);

int main(){
   tGrille grille1;
   int numLigne, numColonne, valeur;
   
   chargerGrille(grille1);
   affichegrille(grille1);
   grille1[3][3].nbCandidats = 9;
   metcandidat(grille1);
   if(grille1[1][2].candidats[9]==true){
      printf("oui");
   }else{
      printf("non");
   }
   
  
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
      }   printf("Grille pleine, fin de partie");


      
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
   laCase.candidats[val] = true;
}

void retirerCandidat(tCase1 laCase, int val){
   laCase.nbCandidats=laCase.nbCandidats-1;
   laCase.candidats[val] = false;
}
bool estCandidat(tCase1 laCase, int val){
    bool fin;
    if(laCase.candidats[val]==true){
        fin = true;
    }else{
        fin=false;
    }
    return fin;
}
int nbCandidats(tCase1 laCase){
   return laCase.nbCandidats;
}


void metcandidat(tGrille tab){
    int collonne=0;
    int ligne=0;
    int x=N-1;
    int y=N-1;
    bool fin=false;

    for (int ligne = 0; ligne < TAILLE; ligne++)
    {
        for (int collonne = 0; collonne < TAILLE; collonne++)
        {
            if(tab[ligne][collonne].valeur==0)
            {
               if(tab[ligne][collonne].valeur==0)
               {
                  for (int z = 0; z < TAILLE; z++)
                  {
                     if (tab[ligne][z].valeur!=0)
                     {
                        retirerCandidat(tab[ligne][collonne],tab[ligne][z].valeur);
                     }
                     if (tab[z][collonne].valeur!=0)
                     {
                        retirerCandidat(tab[ligne][collonne],tab[z][collonne].valeur);    
                     }
                  }
                     
               }
               while (fin==false&&x<=8)
               {
                  y=N-1;
                  while (fin==false&&y<=8)
                  {
                     if (ligne <= x && collonne <= y) {
                        fin=true;
                        for (int i = x; i < x-2; i--)
                        {
                           for (int j = y; j < y-2; j--)
                           {
                              if (tab[x][y].valeur!=0)
                              {
                                 retirerCandidat(tab[ligne][collonne],tab[x][y].valeur);
                                 printf("3");
                              }
                              
                           }
                           
                        }
                        
                     }
                     y=y+N;
                  }
                  x=x+N;
               }
               
            
            }
         }
        
      
    
    
    }
}

void initialise(tGrille tab){
   for (int i = 0; i < TAILLE; i++)
   {
      for (int j = 0; j < TAILLE; j++)
      {
         if (tab[i][j].valeur==0)
         {
            for (int x = 1; x < 10; x++)
            {
               ajouterCandidat(tab[i][j],x);
            }            
         }
         
         
         
      }
      
   }
   
}
