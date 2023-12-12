#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//déclaration des constante
#define N 5
const char fin[] = "*";
typedef float tout[N][N];
void initialise(tout nbpersonnen,tout nbfilm);
void personne(tout nbpersonne,tout nbfilm);
float moyenne(tout nbpersonne,tout nbfilm);
int main(){
   //déclaration des variables
    tout nbpersonnen;
    tout nbfilm;
    initialise(nbpersonnen,nbfilm);
    personne(nbpersonnen,nbfilm);
    printf("%2.f",moyenne(nbpersonnen,nbfilm));

   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void initialise(tout nbpersonnen,tout nbfilm){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            nbfilm[i][j] = 0;
            nbpersonnen[i][j]=0;
        }
        
    }
    
}

void personne(tout nbpersonne,tout nbfilm){
    char nom[20];
    int categorie;
    int age;
    int film;
    printf("quelle nom\n");
    scanf("%s",nom);
    while (strcmp(nom,fin)!=0)
    {
        printf("catégorie\n");
        scanf("%d",&categorie);
        printf("age\n");
        scanf("%d",&age);
        printf("film\n");
        scanf("%d",&film);
        nbpersonne[categorie-1][age-1]++;
        nbfilm[categorie-1][age-1]=nbfilm[categorie-1][age-1]+film;
        printf("quelle nom\n");
        scanf("%s",nom);    
    }
    
}

float moyenne(tout nbpersonne,tout nbfilm){
    int categorie;
    int age;
    float resultat;
    printf("catégorie\n");
    scanf("%d",&categorie);
    printf("age\n");
    scanf("%d",&age);
    if(nbpersonne[categorie-1][age-1] !=0){
        
        resultat = nbfilm[categorie-1][age-1]/nbpersonne[categorie-1][age-1];        

        
    }else{
        printf("division par 0");
    }
    return resultat;
}

