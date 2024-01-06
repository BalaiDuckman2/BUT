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


   void chargerGrille(tGrille grille, char nomFichier[TAILLE_FICHIER]);
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
   
   int possibleCaché(tGrille grille, int ligne, int colonne, int valeur);
   void singletonCaché(tGrille tab);
   int nbCaseVide(tGrille tab);
   int nbCandidatsElimine(tGrille tab);
   void statistique(tGrille grille,int nbCaseVideInitial,int nbCandidatsInitial,char nomFichier[TAILLE_FICHIER]);   

   int main(){
      tGrille grille1;
      int numLigne, numColonne, valeur,nbCaseInitial,nbCandidatsInitial;
      char nomFic[TAILLE_FICHIER];
      chargerGrille(grille1,nomFic);
      nbCaseInitial=nbCaseVide(grille1);
      nbCandidatsInitial=nbCandidatsElimine(grille1);
      affichegrille(grille1);

      initialise(grille1);
      
      while(nbCaseVide(grille1)!=0)
      {
         singletonNu(grille1);
         singletonCaché(grille1);   
         affichegrille(grille1);
         
      
      }
      statistique(grille1,nbCaseInitial,nbCandidatsInitial,nomFic);
      
      return EXIT_SUCCESS;
   }



   void chargerGrille(tGrille grille, char nomFichier[TAILLE_FICHIER]){
      
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
                     
                     tab[i][j].valeur= x;
                     initialise(tab);
                  }
               }
            }
         }
      }
      
   }
   
}

int possibleCaché(tGrille grille, int ligne, int colonne, int valeur) {
    bool fin = true;
    int i, j, recupi, recupj;
    bool finboucle = false;
    int compteur=0;


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
                           if (grille[i - 1][j - 1].valeur==0)
                           {
                              for (int x = 0; x < grille[i - 1][j - 1].nbCandidats; x++)
                              {
                                 if (grille[i - 1][j - 1].candidats[x]==valeur) {
                                    compteur=compteur+1;
                                 }
                              }
                              
                              
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
    return compteur;
}

void singletonCaché(tGrille tab){
   for (int i = 0; i < TAILLE; i++)
   {
      for (int j = 0; j < TAILLE; j++)
      {
         

         if (tab[i][j].valeur==0){
            for (int x = 1; x < 10; x++)
            {
               for (int y = 0; y < tab[i][j].nbCandidats; y++)
               {
                  if (tab[i][j].candidats[y]==x)
                  {
                     if (possibleCaché(tab,i,j,x)==1)
                     {
                        
                        tab[i][j].valeur=x;
                        initialise(tab);
                        x=10;
                     }
                  }
               }
               
               
            }
               
               
               
         }
            
      }

   }

   }

int nbCaseVide(tGrille tab){
   int totale=0;
   for (int i = 0; i < TAILLE; i++)
   {
      for (int j = 0; j < TAILLE; j++)
      {
         if (tab[i][j].valeur==0)
         {
            totale++;
         }
         
      }
      
   }
   return totale;
   
}
int nbCandidatsElimine(tGrille tab){
   int totale=0;
   for (int i = 0; i < TAILLE; i++)
      {
         for (int j = 0; j < TAILLE; j++)
         {
            if (tab[i][j].valeur==0)
            {
               
               for (int x = 1; x < 10; x++)
               {
                  
                  if (possible(tab, i, j, x)==true) {
                     totale++;
                     

                  }
               }            
            }
            
            
            
         }
         
      }
      return totale;
}
void statistique(tGrille grille, int nbCaseVideInitial,int nbCandidatsInitial,char nomFichier[TAILLE_FICHIER]){
   float taux,pourcentage;
   int nbCaseVideFinal = nbCaseVide(grille);
   int nbCandidatsFinal = nbCandidatsElimine(grille);
   nbCaseVideFinal =nbCaseVideInitial-nbCaseVideFinal;
   nbCandidatsFinal= nbCandidatsInitial-nbCandidatsFinal;

   if (nbCandidatsFinal==0)
   {
      
      pourcentage=0;
   }else{
      pourcentage=(nbCandidatsInitial/nbCandidatsFinal)*100;
   }
   if (nbCaseVideFinal==0 )
   {
      taux=0;
   }else{
      taux=(nbCaseVideInitial/nbCaseVideFinal)*100;
   }
   
   
   printf("\n\n***** Résultat pour %s ******\n\n",nomFichier);
   printf("Nombre de cases remplies = %d sur %d  Taux de remplissage = %.2f\n\n",nbCaseVideFinal,nbCaseVideInitial,taux);
   printf("Nombre de Candidats elimines = %d     Pourcentage d'elimination = %.2f\n\n",nbCandidatsFinal,pourcentage);
}