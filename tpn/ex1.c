#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//déclaration des constantes
typedef struct{
    int jour;
    int mois;
    int an;
} date;

typedef char chaine20[21];
typedef struct{
    chaine20 nom;
    chaine20 prenom;
    date naissance;
    date mort;
} ecrivain;

void afficheDate(date d);
void lireDate(date *d);
int compare(date d1, date d2);
void lister(char nomFic[]);
bool existe(char nomFic[], chaine20 nom);
void ajouter(char nomFic[]);
void copierDansTableau(char nomFic[],ecrivain t[], int *nb);
bool contemporain(ecrivain e1, ecrivain e2);
void afficherMatrice(ecrivain t[], int nb);
int main(){
   //déclaration des variables
   
   // saisie des données
   


   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void afficheDate(date d){
    if(d.jour ==0 && d.mois == 0 && d.an ==0){
        printf("--/--/--");
    }else{
        printf("%d/%d/%d",d.jour,d.mois,d.an);
    }
}
void lireDate(date *d){
    printf("jour\n");
    scanf("%d",&d->jour);
    printf("mois\n");
    scanf("%d",&d->mois);
    printf("année\n");
    scanf("%d",&d->an);
}
int compare(date d1, date d2){
    int fin;
    if(d1.an==d2.an){
        if(d1.mois==d2.mois){
            if(d1.jour==d2.jour){
                fin=0;
            }else if(d1.jour<d2.jour){
                fin=1;
            }else{
                fin=0;
            }
        }
        else if(d1.mois<d2.mois){
            fin=1;
        }else{
            fin=0;
        }
    }else if(d1.an<d2.an){
        fin=1;
    }else{
        fin=0;
    }
    return fin;
}
void lister(char nomFic[]){
    FILE * f;
    ecrivain listeE;
    f = fopen(nomFic,"rb");
    fread(&listeE,sizeof(listeE),1,f);
    while (feof(f)==false){
        printf("%s %s (", listeE.nom, listeE.prenom);
        afficheDate(listeE.naissance);
        printf(", ");
        afficheDate(listeE.mort);
        printf(")\n");
        fread(&listeE,sizeof(listeE),1,f);
    }
    fclose(f);
}
bool existe(char nomFic[], chaine20 nom){
    FILE * f;
    ecrivain listeE;
    
    bool fin = false;
    f = fopen(nomFic,"rb");
    fread(&listeE,sizeof(listeE),1,f);    
    while (feof(f)==false){
        if(strcmp(listeE.nom,nom)==0){
            fin=true;
        }
        fread(&listeE,sizeof(listeE),1,f);
    }
    return fin;
}

void ajouter(char nomFic[]){
    FILE * f;
    ecrivain listeE;
    f = fopen(nomFic,"ab");
    printf("nom\n");
    scanf("%s",listeE.nom);
    if(existe(nomFic,listeE.nom)==true){
        printf("existe déjà");
    }else{
        printf("prenom\n");
        scanf("%s",listeE.prenom);
        lireDate(&listeE.naissance);
        lireDate(&listeE.mort);
        if(compare(listeE.naissance,listeE.mort)==1){
            fwrite(&listeE,sizeof(listeE),1,f);
        }else{
            printf("erreur sur le prenom");
        }

        
    }
    
    
    fclose(f);
}

bool contemporain(ecrivain e1, ecrivain e2){
    bool fin=false;
    if((compare(e1.naissance,e2.mort) == 1 || compare(e1.naissance,e2.mort) == 0)  && (compare(e1.naissance,e2.mort) == 1 || compare(e1.naissance,e2.mort) == 0)){
        fin=true;
    }
    return fin;
}

void copierDansTableau(char nomFic[],ecrivain t[], int *nb){
    *nb=0;
    FILE * f;
    ecrivain listeE;
    f = fopen(nomFic,"rb");
    fread(&listeE,sizeof(listeE),1,f);
    while (feof(f)==false)
    {
        fread(&listeE,sizeof(listeE),1,f);
        t[*nb]=listeE;
        *nb++;
    }
    fclose(f);
}

void afficherMatrice(ecrivain t[], int nb){
    for(int i=1;i<13;i++){
        printf("                   %d ",i);
    }
    for(int i=1;i<13;i++){
        printf("%d-%-18s",i,t[i]);
        for (int j = 1; j < 13; j++)
        {
            if(contemporain(t[i],t[j])==true){
                printf(" X ");
            }else{
                printf("   ");
            }
        }
        
    }

    
}