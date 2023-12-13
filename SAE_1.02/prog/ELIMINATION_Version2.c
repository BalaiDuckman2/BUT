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
   void singletonNu(tGrille tab, int *nbCase);
   void initialise(tGrille tab);
   void affiche(tCase1 laCase);
   void statistique(tGrille tab, int *nbCase);
   
   
   
   int main(){
      tGrille grille1;
      int numLigne, numColonne, valeur,nbCase;
      nbCase=0;
      chargerGrille(grille1);
      affichegrille(grille1);
      initialise(grille1);
      statistique(grille1,&nbCase);
      while(nbCase!=0){
         singletonNu(grille1,&nbCase);      
         affichegrille(grille1);
      
      }
      printf("%d",nbCase);
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
         for(int i; i<TAILLE_TOUT;i++){
            fread(&grille[i/TAILLE][i%TAILLE].valeur, sizeof(int), 1, f);
            grille[i/TAILLE][i%TAILLE].nbCandidats = 0;
            for (int j = 0; j < TAILLE+1; j++) {
               grille[i/TAILLE][i%TAILLE].candidats[j] = false;
            }
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

bool possible(tGrille grille, int ligne, int colonne, int valeur) {
    bool fin = true;
    int i, j, recupi, recupj;
    bool finboucle = false;

    i = DEBUT;
    while (fin == true && i < TAILLE) {
        if (valeur == grille[ligne][i].valeur || valeur == grille[i][colonne].valeur) {
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
                    while (finboucle == false && i >= recupi - 2) {
                        recupj = j;
                        while (finboucle == false && j >= recupj - 2) {
                            if (valeur == grille[i - 1][j - 1].valeur) {
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
      return laCase.candidats[val];
   }
   int nbCandidats(tCase1 laCase){
      return laCase.nbCandidats;
   }






   void initialise(tGrille tab){
      for (int i = 0; i < TAILLE; i++)
      {
         for (int j = 0; j < TAILLE; j++)
         {
            if (tab[i][j].valeur==0)
            {
               tab[i][j].nbCandidats=0;
               for (int x = 1; x < 10; x++)
               {
                  if (possible(tab, i, j, x)==true) {
                     tab[i][j].nbCandidats++;
                     tab[i][j].candidats[x]=true;
                     

                  }else{
                     tab[i][j].candidats[x]=false;
                  }
               }            
            }
            
            
            
         }
         
      }
      
}

void singletonNu(tGrille tab, int *nbCase){
   int contient;
   contient = *nbCase;
   for (int i = 0; i < TAILLE; i++)
   {
      for (int j = 0; j < TAILLE; j++)
      {
         

         if (tab[i][j].valeur==0){
            

            if (nbCandidats(tab[i][j])==1)
            {
               for(int x = 1; x<TAILLE+1;x++){
                  if (tab[i][j].candidats[x] == true)
                  {
                     initialise(tab);
                     tab[i][j].valeur= x;
                     contient--;
                     *nbCase=contient;
                     
                  }
               }
            }
         }
      }
      
   }
   
}

void affiche(tCase1 laCase){
   for (int i = 1; i < 10; i++)
   {
      printf("%d\n",laCase.candidats[i]);
   }
   
}


void statistique(tGrille tab, int *nbCase){
   int contient;
   contient = *nbCase;

   for (int i = 0; i < TAILLE; i++)
   {
      for (int j = 0; j < TAILLE; j++)
      {
         if (tab[i][j].valeur==0)
         {
            contient++;
            *nbCase=contient;
         }
         
      }
      
   }
   
}
