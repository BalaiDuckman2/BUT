#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NM 12
typedef char t_chaine9[10];
typedef  struct{
    t_chaine9 c_nom;
    int      c_nbJours;
} t_mois;
typedef  t_mois t_tabMois[NM];
const t_tabMois  tMois= { {"janvier",31},
                          {"fevrier",28},
                          {"mars",31},
                          {"avril",30},
                          {"mai",30},
                          {"juin",30},
                          {"juillet",30},
                          {"aout",30},
                          {"septembre",30},
                          {"octobre",30},
                          {"novembre",30},
                          {"decembre", 31}
};



void affiche31();
int nombreJours(t_chaine9 nomMois);


int main(){
   //déclaration des variables
    affiche31();
    t_chaine9 j ="octobre";
    printf("%d",nombreJours(j));


   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void affiche31(){ 
    for(int i=0;i<12;i++){
        if(tMois[i].c_nbJours==31){
            printf("%s\n",tMois[i].c_nom);
            
        }
    }
}

int nombreJours(t_chaine9 nomMois){
    int i=0;
    bool finboucle = false;
    int fin;
    while (i<12 && finboucle == false)
    {
        if (strcmp(nomMois, tMois[i].c_nom)==0)
        {
            fin = tMois[i].c_nbJours;
            finboucle = true;
        }
        
        i++;
    }
    return fin;
}