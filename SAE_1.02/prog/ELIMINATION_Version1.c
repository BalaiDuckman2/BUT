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

   void ajouterCandidat(tCase1 *laCase, int val);
   void retirerCandidat(tCase1 *laCase, int val);
   bool estCandidat(tCase1 laCase, int val);
   int nbCandidats(tCase1 laCase);
   void singletonNu(tGrille tab);
   void initialise(tGrille tab);
   void affiche(tCase1 laCase);
   void singleCache(tGrille tab);
   int nbCandCase(tGrille grille,int ligne,int colonne,int valeur);
   
   
   int main(){
      tGrille grille1;
      int numLigne, numColonne, valeur,nbCase;
      nbCase=0;
      chargerGrille(grille1);
      affichegrille(grille1);
      initialise(grille1);
      for(int i=0; i<7;i++){
         singleCache(grille1);      
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


   void ajouterCandidat(tCase1 *laCase, int val){
      laCase->candidats[laCase->nbCandidats] = val;
      laCase->nbCandidats++;
      
      
   }

   void retirerCandidat(tCase1 *laCase, int val){
      int i = 0;
      int n =0;
      laCase->nbCandidats--;
      while (i<laCase->nbCandidats)
      {
         if (laCase->candidats[i] == val && n==1)
         {
            laCase->candidats[i] = laCase->candidats[i+1];
            n=1;
         }
         
         
         
         i++;
      }
      

   }
   bool estCandidat(tCase1 laCase, int val){
      int i=0;
      bool finboucle=false;
      while (i<laCase.nbCandidats && finboucle == false)
      {
         if (val == laCase.candidats[i])
         {
            finboucle = true;
         }
         i++;
      }
      return finboucle;
   }
   int nbCandidats(tCase1 laCase){
      return laCase.nbCandidats;
   }






   void initialise(tGrille tab){
      for (int i = 0; i < TAILLE; i++)
      {
         for (int j = 0; j < TAILLE; j++)
         {
            tab[i][j].nbCandidats=0;
            if (tab[i][j].valeur==0)
            {
               
               
               
               for (int x = 1; x < 10; x++)
               {
                  
                  if (possible(tab, i, j, x)==true) {
                     
                     ajouterCandidat(&tab[i][j],x);
                     printf("%d",tab[i][j].nbCandidats);

                  }

               }            
            }
            
            
            
         }
         
      }
      
}

void singletonNu(tGrille tab){
   for (int i = 0; i < TAILLE; i++)
   {
      for (int j = 0; j < TAILLE; j++)
      {
         

         if (tab[i][j].valeur==0){
            if (nbCandidats(tab[i][j])==1)
            {
               for(int x = 1; x<TAILLE+1;x++){
                  if (estCandidat(tab[i][j],x)==true)
                  {
                     initialise(tab);
                     tab[i][j].valeur= x;
                  }
               }
            }
         }
      }
      
   }
   
}

void singleCache(tGrille tab){
   for (int i = 0; i < TAILLE; i++)
   {
      for (int j = 0; j < TAILLE; j++)
      {
         if(tab[i][j].valeur==0)
         {

            for (int x = 0; x < TAILLE; x++)
            {
               if(nbCandCase(tab,i,j,x)==1){
               initialise(tab);
               tab[i][j].valeur= x; 
               }
            }
         }
      }
      
   }
   
   
}

