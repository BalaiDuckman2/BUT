

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//déclaration des constantes
#define MAX 21
typedef char tChaine20[MAX];
typedef struct{
    tChaine20 nom;
    tChaine20 prenom;
    int age; 
}tEtudiant;

void montre(tEtudiant etudiant);
void saisir(tEtudiant *etudiant);
int compare(tEtudiant e1, tEtudiant e2);
int main(){
   //déclaration des variables
    tEtudiant e1, e2;
    saisir(&e1);
    saisir(&e2);
    montre(e1);
    montre(e2);
    if(compare(e1,e2)==1){
        printf("1");
    }
    if(compare(e1,e2)==-1){
        printf("-1");
    }
    if(compare(e1,e2)==0){
        printf("0");
    }


   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void montre(tEtudiant etudiant){
    printf("Étudiant : %s %s, %d\n ",etudiant.prenom,etudiant.nom,etudiant.age);
}

void saisir(tEtudiant *etudiant){
    printf("prenom\n");
    scanf("%s",(*etudiant).prenom);
    printf("nom\n");
    scanf("%s",(*etudiant).nom);
    printf("age\n");
    scanf("%d",&(*etudiant).age);
}


int compare(tEtudiant e1, tEtudiant e2){
    int fin;
    if(e1.age < e2.age){
        fin = -1;
    }
    if(e1.age > e2.age){
        fin = 1;
    }
    if(e1.age == e2.age){
        fin = 0;
    }
    return  fin;
}
