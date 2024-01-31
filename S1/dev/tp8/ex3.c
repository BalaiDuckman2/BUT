#include <stdlib.h>
#include <stdio.h>
#define N 8
typedef char mot8lettres[N];

void init(mot8lettres tablo);
void saisir(mot8lettres tablo);
void afficher(mot8lettres tablo);
int contient(mot8lettres tablo, char caractere);

//déclaration des constantes


int main(){
   //déclaration des variables
    int verif;
    mot8lettres tab;
    init(tab);
    saisir(tab);
    afficher(tab);
    verif = contient(tab,'x');
    if(verif == 1){
        printf("il contient la lettre");
    }else{
        printf("il ne contient pas la lettre");
    }
   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void init(mot8lettres tablo){
    for(int i = 0; i < N; i++)
    {
        tablo[i] = '*';
    }
    
}

void saisir(mot8lettres tablo){
    
    printf("rentrer un mot de 8 lettre\n");
    scanf("%s",tablo);
    
    
}

void afficher(mot8lettres tablo){
    for(int i = 0; i < N; i++)
    {
        printf("%c",tablo[i]);
    }
}

int contient(mot8lettres tablo, char caractere){
    for(int i=0; i<N; i++){
        if(tablo[i]==caractere){
            return 1;
        }
    }
    return 0;
}