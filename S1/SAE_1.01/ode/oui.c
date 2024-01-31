#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

if(fin==true){
      i=DEBUT;
      while(fin==true && i<=N*N-1 ){
         i=i+N;
         j=DEBUT;
         while(fin == true && j <=N*N-1)
         {
            j=j+N;  
            if (ligne < i && colonne < j)
            {
               int recup1=i
               recup=j;
               while(fin ==true && i!=recup1-3)
               {
                  
                  while(fin == true && j!=recup-3)
                  {
                     printf("%d",j);
                     if (valeur==grille[i-1][j-1])
                     {    
                        fin = false;
                     }
                     
                     j=j-1;
                  }
                  j=recup;
                  i=i-1;
                  
               }
               i=N*N;
               j=N*N;
            }
            
         }
         
      }   
   }
   return fin;

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

bool fin = true;
int recupi;
int recupj;
bool finboucle = false;
while (finboucle==false && i<=9)
{
    int j = 3;
    while (finboucle==false && j<=8)
    {
        if (ligne < i && colonne < j){
            recupi = i;
            while(finboucle == false && i <= recupi-2)
            {
                recupj = j;
                while (finboucle==false && j <= recupj-2)
                {
                    if (valeur==grille[i-1][j-1]){
                        finboucle =true;
                    }
                    j=j-1;
                }
                
                i=i-1;
            }
            fin = true
            finboucle = true;
        }
        j=j+3
    }
    i=i+3
}
