#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//déclaration des constantes
const int WIN = 20;
const char JOUEUR_A = 'A';
const char JOUEUR_B = 'B';

void  faireJouer(char j, int *score);
void afficherResultat(int score1,int score2);
int main(){
   //déclaration des variables
    int score1;
    score1 = 0;
    int score2;
    score2 = 0;    
   // saisie des données



   // traitement des données
    while (score1 < WIN  && score2 < WIN)
    {
        faireJouer(JOUEUR_A,&score1);
        afficherResultat(score1,score2);
        
        if(score1 < WIN){
            faireJouer(JOUEUR_B,&score2);
            afficherResultat(score1,score2);
        }
    }
    


   // affichage des résultats



   return EXIT_SUCCESS;
}

void  faireJouer(char j, int *score){
    int total;
    printf("%c combien avez vous fait\n",j);
    scanf("%d",&total);
    *score = total+ *score;
    
    while (total==6)
    {
        printf("%c bravo 6\n",j);
        printf("%c combien avez vous fait\n",j);
        scanf("%d",&total);
        *score = total+ *score;
        if (*score >= WIN)
        {   
            total=0;
        }
        
    }
    

}

void afficherResultat(int score1,int score2){
    if(score1 >= WIN){
        printf("le joueur A à gagner avec %d points\n",score1);
        printf("le joueur B avait %d points\n",score2);
    }
     if(score2 >= WIN){
        printf("le joueur B à gagner avec %d points\n",score2);
        printf("le joueur A avait %d points\n",score1);
    }

}