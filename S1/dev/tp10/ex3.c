#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//déclaration des constantes
#define MAX 198 // 22 équipes de 9 coureurs = 198 coureurs
typedef struct{
    int c_numero;
    int c_temps;
}t_concurrent;
typedef t_concurrent t_tabconc[MAX];



void insere( t_concurrent c, t_tabconc tc, int n );
void permuter(t_concurrent *c1, t_concurrent *c2);
void affiche_classement ( t_tabconc tc, int n );
int main(){
   //déclaration des variables
   bool fin1 = false;
   bool fin = false;
   int n =0;
   int y =0;
   t_concurrent coureur;
   t_tabconc classement;
    while (fin1==false)
    {
        fin = false;
        printf("numero\n");
        scanf("%d",&coureur.c_numero);
        printf("temps\n");
        scanf("%d",&coureur.c_temps);
        insere(coureur,classement,n);
        while (fin==false)
        {
            
            if (&classement[y].c_temps < &classement[y-1].c_temps)
            {
                permuter(&classement[y],&classement[y-1]);
                y-1;
                
            }
            else
            {
                fin = true;
            }
            
        }
        affiche_classement(classement,n);
        n++;
        y=n;
    }
    


   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void insere( t_concurrent c, t_tabconc tc, int n ){
    tc[n].c_numero = c.c_numero;
    tc[n].c_temps = c.c_temps;
}

void permuter(t_concurrent *c1, t_concurrent *c2){
    t_concurrent cContient;
    cContient = *c1;
    *c1 = *c2;
    *c2 = cContient;
}

void affiche_classement ( t_tabconc tc, int n ){
    for(int i=0;i<=n;i++){
        printf("%d : %d %d\n",i+1,tc[i].c_numero, tc[i].c_temps);
    }
}