   #include <stdlib.h>
   #include <stdio.h>
   #include <string.h>
   #include <stdbool.h>
   #include <time.h>

   //déclaration des constantes
   const int TAILLE_FICHIER = 30;
   #define N 4
   const int DEBUT = 0;
   #define TAILLE (N*N) 
   #define TAILLE_TOUT (TAILLE*TAILLE)

   //déclaration du type tGrille 
   typedef struct {
      int valeur;
      bool candidats[TAILLE+1];
      int nbCandidats;
   } tCase1;

   typedef tCase1 tGrille[TAILLE][TAILLE];


   void chargerGrille(tGrille grille, char nomFichier[TAILLE_FICHIER]);
   void affichegrille(tGrille grille);
   void saisir(int *valeur);
   bool possible(tGrille grille,int ligne,int colonne,int valeur);
   bool grilleComplete(tGrille grille);
   bool backtracking(tGrille grille, int numeroCase);


   void ajouterCandidat(tCase1 laCase, int val);
   void retirerCandidat(tCase1 laCase, int val);
   bool estCandidat(tCase1 laCase, int val);
   int nbCandidats(tCase1 laCase);
   void singletonNu(tGrille tab);
   void initialise(tGrille tab);
   void initialiseCase(tGrille tab, int ligne, int colonne);
   int possibleCaché(tGrille grille, int ligne, int colonne, int valeur);
   void singletonCaché(tGrille tab);
   int nbCaseVide(tGrille tab);
   int nbCandidatsElimine(tGrille tab);
   void statistique(tGrille grille, float nbCaseVideInitial,float nbCandidatsInitial,char nomFichier[TAILLE_FICHIER]);
   void paireNue(tGrille grille);
   void paireNueCaché(tGrille grille);
   int cherchecandidat(tGrille grille, int i, int j,int nombre);


   int main(){
      tGrille grille1;
      int nbCase=0;
      int nbCase2=-1;
      int numLigne, numColonne, valeur,nbCaseInitial,nbCandidatsInitial;
      char nomFic[TAILLE_FICHIER];
      chargerGrille(grille1,nomFic);
      nbCaseInitial=nbCaseVide(grille1);
      nbCandidatsInitial=nbCandidatsElimine(grille1);
      
      affichegrille(grille1);
      
      srand(time(NULL));
      
      clock_t begin = clock();
      initialise(grille1);
      while(nbCase!=nbCase2)
      {
         
         nbCase=nbCaseVide(grille1);
         singletonNu(grille1);
         singletonCaché(grille1);                                          
         nbCase2=nbCaseVide(grille1);
        
         
      }
      
      
      backtracking(grille1,0);
      clock_t end = clock();
      affichegrille(grille1);
      double  tmpsCPU = (end - begin)*1.0 / CLOCKS_PER_SEC;
      printf( "\nTemps CPU = %.8f secondes\n",tmpsCPU);

      return EXIT_SUCCESS;
   }




   void chargerGrille(tGrille grille, char nomFichier[TAILLE_FICHIER]){
      
      FILE * f;
      nomFichier = "MaxiGrilleB.sud";
      //printf("Nom du fichier : ");
      //scanf("%s", nomFichier);
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
   
   printf("  +--------------------+--------------------+--------------------+--------------------+\n  |");

   for(int ligne=DEBUT; ligne<TAILLE; ligne++){
      
      for(int collone=DEBUT; collone <TAILLE;collone++){
         if(grille[ligne][collone].valeur==0){
            printf("  .  ");
         }else{
            printf(" %3d ",grille[ligne][collone].valeur);
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
                    while (finboucle == false && i >= recupi - 3) {
                        recupj = j;
                        while (finboucle == false && j >= recupj - 3) {
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

bool backtracking(tGrille grille, int numeroCase){
   int ligne=0,colonne=0;
   bool resultat=false;
   if (numeroCase == TAILLE*TAILLE)
   {
      resultat=true;
   }else{
      ligne=numeroCase/TAILLE;
      colonne=numeroCase%TAILLE;
      if (grille[ligne][colonne].valeur!=0)
      {
         resultat= backtracking(grille,numeroCase+1);
      }else{
         for (int valeur = 1; valeur <= TAILLE; valeur++)
         {
            if (possible(grille,ligne,colonne,valeur))
            {
               grille[ligne][colonne].valeur=valeur;
               if (backtracking(grille,numeroCase+1)==true)
               {
                  resultat=true;
               }else{
                  grille[ligne][colonne].valeur=0;
               }
               
            }
            
         }
         
      }
      
   }
   return resultat;
   
}

void initialiseCase(tGrille tab, int ligne, int colonne){
   for (int i = 0; i < TAILLE; i++)
   {
      tab[i][colonne].nbCandidats=0;
      tab[ligne][i].nbCandidats=0;
      for (int x = 1; x < TAILLE+1; x++)
      {
         
         if (possible(tab, i, colonne, x)==true && tab[i][colonne].valeur==0 ) {
            tab[i][colonne].nbCandidats++;
            tab[i][colonne].candidats[x]=true;
            
         }else{
            tab[i][colonne].candidats[x]=false;
         }
         if (possible(tab, ligne, i, x)==true && tab[ligne][i].valeur==0 ) {
            tab[ligne][i].nbCandidats++;
            tab[ligne][i].candidats[x]=true;
         }else{
            tab[ligne][i].candidats[x]=false;
         
         }

      }
      
   }   
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
               for (int x = 1; x < TAILLE+1; x++)
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

void singletonNu(tGrille tab){
   
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
                     
                     tab[i][j].valeur= x;
                     
                     initialiseCase(tab,i,j);
                     
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
                    while (finboucle == false && i >= recupi - 3) {
                        recupj = j;
                        while (finboucle == false && j >= recupj - 3) {
                           if (grille[i - 1][j - 1].valeur==0)
                           {
                           
                              if (grille[i - 1][j - 1].candidats[valeur]==true) {
                                 compteur=compteur+1;
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
            for (int x = 1; x < TAILLE+1; x++)
            {

               if (tab[i][j].candidats[x]==true)
                  
                  
               {
                  if (possibleCaché(tab,i,j,x)==1)
                  {
                     
                     tab[i][j].valeur=x;
                     initialiseCase(tab,i,j);
                     x=TAILLE+1;
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
               
               for (int x = 1; x < TAILLE+1; x++)
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
void statistique(tGrille grille, float nbCaseVideInitial,float nbCandidatsInitial,char nomFichier[TAILLE_FICHIER]){
   float taux,pourcentage;
   float nbCaseVideFinal = nbCaseVide(grille);
   float nbCandidatsFinal = nbCandidatsElimine(grille);
   nbCaseVideFinal =nbCaseVideInitial-nbCaseVideFinal;
   nbCandidatsFinal= nbCandidatsInitial-nbCandidatsFinal;

   if (nbCandidatsFinal==0)
   {
      
      pourcentage=0;
   }else{
      pourcentage=(nbCandidatsFinal/nbCandidatsInitial)*100;
   }
   if (nbCaseVideFinal==0 )
   {
      taux=0;
   }else{
      taux=(nbCaseVideFinal/nbCaseVideInitial)*100;
   }
   
   
   printf("\n\n***** Résultat pour %s ******\n\n",nomFichier);
   printf("Nombre de cases remplies = %.0f sur %.0f  Taux de remplissage = %.2f%%\n\n",nbCaseVideFinal,nbCaseVideInitial,taux);
   printf("Nombre de Candidats elimines = %.0f     Pourcentage d'elimination = %.2f%%\n\n",nbCandidatsFinal,pourcentage);
}


void paireNue(tGrille grille){
   int coord1[2];
   int coord2[2];
   bool paire1[2];
  int x=0;
  int y=0;
  bool fin=false;
   
   
   
   for (int i = 2; i <= 8; i=i+N)
   {
      x=i;
      for (int j = 2; j <= 8; j=j+N)
      {
         y=j;
         
         
            while (x!=i-2&&fin==false)
            {
               while (y!=j-2 && fin==false)
               {
                  if (grille[x][y].valeur==0)
                  {
                     
                     if(grille[x][y].nbCandidats==2)
                     {
                        int valpaire=0;
                        paire1[0]=0;
                        paire1[1]=0;
                        coord1[0]=x;
                        coord1[1]=y;
                        for (int k = 1; k < 10; k++)
                        {
                           if (grille[x][y].candidats[k]==true)
                           {
                              paire1[valpaire]=k;
                              valpaire++;
                              
                              fin=true;
                           }
                        }
                     }
                  }
                  y--;
               }
               
               x--;
            }
            while (x!=i-2&&fin==true)
            {
               while (y!=j-2&&fin==true)
               {
                  if(grille[x][y].nbCandidats==2)
                  {
                     coord2[0]=0;
                     coord2[1]=0;
                     if (grille[x][y].candidats[paire1[0]]==true && grille[x][y].candidats[paire1[1]]==true)
                     {
                        coord2[0]=x;
                        coord2[1]=y;
                        for (int u = i; u > i-2; u--)
                           {
                              for (int p = j; p > j-2; p--)
                              {
                                 
                                 if (coord1[0]!=u||coord1[1]!=p)
                                 {
                                    if (coord2[0]!=u||coord2[1]!=p)
                                    {
                                       
                                       grille[u][p].candidats[paire1[0]]=false;
                                       grille[u][p].candidats[paire1[1]]=false;
                                       fin=false;
                                    }
                                 }
                              }
                           }
                     }
                     
                  }
                  j--;
               }
               x--;
            }
            
         }
      }
}

int cherchecandidat(tGrille grille, int i, int j,int nombre){
   int compteur=0;
   for (int x = i; x > i-2; x--)
   {
      for (int y = j; y > j-2; y--)
      {
         if(grille[x][y].valeur==0){
            
               if (grille[x][y].candidats[nombre]==true)
               {
                  compteur++;
                  
                  
               }
               
            
            
         }
      }
   }
   return compteur;
}
   
void paireNueCaché(tGrille grille){
   int compteur=0;
   bool nbCandidats[10];
   
   
   for (int i = 2; i <= 8; i=i+N)
   {
      for (int j = 2; j <= 8; j=j+N)
      {
         for (int k = 1; k < 10; k++)
         {
            
            nbCandidats[k]=false;
         }
         compteur=0;
         for (int k = 1; k < 10; k++)
         {
            
            if(cherchecandidat(grille,i,j,k)==2){
               nbCandidats[k]=true;
               compteur++;
            }
            
         }
         if(compteur>2)
         {
            for (int k = 1; k < 10; k++)
            {
               if (nbCandidats[k]==true)
               {
                  for (int p = 1; p < 10; p++)
                  {
                     if (nbCandidats[p]==true&&p!=k)
                     {
                        for (int x = i; x > i-2; x--)
                        {
                           for (int y = j; y > j-2; y--)
                           {
                              compteur=0;
                              
                              if (grille[x][y].candidats[k]==true&&grille[x][y].candidats[p]==true)
                              {
                                    compteur++;
                                    
                                    
                              }

                                 
                              
                              if (compteur==1)
                              {
                                 
                                 for (int m = x; m > i-2; m--)
                                 {
                                    for (int l = y; l > j-2; l--)
                                    {
                                       compteur==0;
                                       if (m!=x||l!=y)
                                       {
                                          
                                          if (grille[m][l].candidats[k]==true&&grille[m][l].candidats[p]==true)
                                          {
                                             compteur++;
                                          }

                                             
                                          if (compteur==1)
                                          {
                                             for (int b = 1; b < 10; b++)
                                             {
                                                if (b!=k&&b!=p)
                                                {
                                                   grille[x][y].candidats[b]=false;
                                                   grille[m][l].candidats[b]=false;
                                                }
                                                
                                             }
                                             
                                             
                                          }
                                          
                                       }
                                    }
                              }
                              
                              
                           }
                     
                        }
                  
                  }
               
         }
                  
      }

         
   }

}
}
}  
} 
}


