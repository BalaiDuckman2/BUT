#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//déclaration des constantes
#define MAX 100
typedef char t_chaine50[51] ;
typedef char t_chaine10[11] ;
typedef struct{ 
    t_chaine50 c_nom;   // nom de l’abonné
    t_chaine10 c_num; // numéro de cet abonné
    int c_duree;  // durée pour laquelle il est abonné
} t_abonne ;
typedef t_abonne t_tabAbo[MAX];

void creer(char nomFic[]);
void liste(char nomFic[]);
void ajouter(char nomFic[]);
bool estdedans(char nomFic[], t_abonne abonne);
void copier(char nomFic[], t_tabAbo t_abo);
void trier(t_tabAbo t_abo, int nb);
void recopier(char nomFic[], t_tabAbo t_abo, int nb);
void permuter(t_abonne *abo1, t_abonne *abo2);
void trieg(char nomFic[]);
int main(){
   //déclaration des variables
    int choix=1;
    char nomfic[20]="abonne";
    while (choix!=0)
    {
        printf("(1)creer\n(2)ajouter\n(3)liste\n(0)quitter\n");
        scanf("%d",&choix);
        if (choix==1)
        {
            creer(nomfic);
 
        }
        if (choix==2)
        {
            liste(nomfic);
   
        }
        if (choix==3)
        {
            trieg(nomfic);
        }
        
    }
    
    

   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void creer(char nomFic[]){
    FILE * f;
    t_abonne abo;
    f = fopen(nomFic,"wb");
    printf("nom\n");
    scanf("%s",abo.c_nom);
    while (strcmp(abo.c_nom,"*")!=0)
    {
        printf("num\n");
        scanf("%s",abo.c_num);
        printf("duré\n");
        scanf("%d",&abo.c_duree);
        fwrite(&abo,sizeof(abo),1,f);
        printf("nom\n");
        scanf("%s",abo.c_nom);
    }
    fclose(f);
    
    


}

void liste(char nomFic[]){
    FILE * f;
    t_abonne abo;
    f = fopen(nomFic,"rb");        
    fread(&abo,sizeof(abo),1,f);
    while (feof(f)==false)
    {
        
        printf("%s\n",abo.c_nom);
        printf("%s\n",abo.c_num);
        printf("%d\n",abo.c_duree);
        fread(&abo,sizeof(abo),1,f);


    }
    fclose(f);
}

void ajouter(char nomFic[]){
    FILE * f;
    t_abonne abo;
    f = fopen(nomFic,"ab");
    printf("nom\n");
    scanf("%s",abo.c_nom);
    while (strcmp(abo.c_nom,"*")!=0)
    {
        printf("num\n ");
        scanf("%s",abo.c_num);
        printf("duré\n");
        scanf("%d",&abo.c_duree);
        fwrite(&abo,sizeof(abo),1,f);
        printf("nom\n");
        scanf("%s",abo.c_nom);
    }
    fclose(f);
}

bool estdedans(char nomFic[], t_abonne abonne){
    bool fin = false;
    FILE * f;
    t_abonne abo;
    f = fopen(nomFic,"rb");
    fread(&abo,sizeof(abo),1,f);
    while (feof(f)==false&& fin==false)
    {
        if (abo.c_num==abonne.c_num)
        {
            fin = true;
        }
        
    }
    return fin;
}


void copier(char nomFic[], t_tabAbo t_abo){
    int i=0;
    FILE * f;
    t_abonne abo;
    f = fopen(nomFic,"rb");
    while (feof(f)==false)
    {
        fread(&abo,sizeof(abo),1,f);
        t_abo[i]=abo;
        i++;
    }
    fclose(f);
}
void trier(t_tabAbo t_abo , int nb){
    bool fin =false;
    int i=0;
    int y=0;
    while (i<nb)
    {
        
        if(strcmp(t_abo[i].c_nom,t_abo[i+1].c_nom)>0){
            printf("o");
            permuter(&t_abo[i],&t_abo[i+1]);
            i++;
            y=i;
            while (strcmp(t_abo[y].c_nom,t_abo[y+1].c_nom)>0)
            {
                permuter(&t_abo[y],&t_abo[y+1]);
                y++;
            }
            
        }else{
            i++;
        }
              
    }
    
    
}
void recopier(char nomFic[], t_tabAbo t_abo, int nb){
    int i=0;
    FILE * f;
    t_abonne abo;
    f = fopen(nomFic,"wb");
    while (i<nb)
    {   
        abo=t_abo[i];
        fwrite(&abo,sizeof(abo),1,f);
        
        i++;
    }
    fclose(f);
}

void permuter(t_abonne *abo1, t_abonne *abo2){
    t_abonne conteneur;
    conteneur = *abo1;
    *abo1 = *abo2;
    *abo2 = conteneur;

}


void trieg(char nomFic[]){
    t_tabAbo abo;
    copier(nomFic,abo);
    trier(abo,4);
    recopier(nomFic,abo,4);
}