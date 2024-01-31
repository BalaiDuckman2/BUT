#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//tableau

FILE * f;
f = fopen(nomFic,"wb");
f = fopen(nomFic,"ab");
f = fopen(nomFic,"rb");

fclose(f);
fwrite(&abo,sizeof(abo),1,f);
fread(&abo,sizeof(abo),1,f);


//trie

void tri_selection(tab t){
    int conteneur;
    for(int i=0; i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(t[i]>t[j]){
                conteneur=t[i];
                t[i]=t[j];
                t[j]=conteneur;
            }
        }
    }
}



t_abonne conteneur;
int compteur;
compteur = 0;
for (int x = 0; x < nb; x++)
{
    for(int y=x+1; y<nb ;y++){
        if(strcmp(t_abo[y].c_nom,t_abo[x].c_nom)<0){
            conteneur = t_abo[y];
            t_abo[y] = t_abo[x];
            t_abo[x] = conteneur;
            
        }
    }
}