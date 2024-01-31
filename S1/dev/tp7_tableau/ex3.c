#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
#define N 21
typedef int note[N];
void initTab(note tab);
void mjTab(note tab, int note);
void affiche(note tab);

int main(){
   //déclaration des variables
    note tableau;
    int note;

    printf("quelle note");
    scanf("%d",&note);

   // saisie des données
    initTab(tableau);
    while (note !=-1)
    {   
        
        mjTab(tableau,note);
        printf("quelle note");
        scanf("%d",&note);
        
    }
    affiche(tableau);

   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void initTab(note tab){
    for (int i = 0; i < N; i++)
    {
        tab[i]=0;
    }
    
}

void mjTab(note tab, int note){
    tab[note]= tab[note]+1;
    
    
}
void affiche(note tab){
    for (int i = 0; i < N; i++)
    {
        if (tab[i] >1)
        {
            printf("%d nb :%d\n",i,tab[i]);
        }
        
    }
    
}


