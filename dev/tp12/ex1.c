

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 50
#define ELTVIDE 0
typedef char chaine10[11] ;
typedef struct{
    chaine10 reference;
    int dateEntStock;
} produit;
int main(){
   //déclaration des variables



   // saisie des données



   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void empiler(produit *adrPile, char elt){
    if(!(estPleine(*adrPile))) {
        adrPile->reference[adrPile->dateEntStock]=elt ;
        adrPile->dateEntStock=adrPile->dateEntStock+1;
        // Attention aux indices du tableau
    }
    else{
        printf("La pile est pleine");
    }
}



char depiler(produit *adrPile){
    char elt;
    if (!(estVide(*adrPile))) {
        elt =adrPile-> reference[adrPile-> dateEntStock-1] ;
        (adrPile-> dateEntStock)--;
        // nettoyage de la pile
        adrPile->reference[adrPile-> dateEntStock] = ELTVIDE;
    }
    else{
        
    }
    return elt;
}

produit initialiser() {
    produit p;
    for (int i=0; i<MAX; i++){
        p.reference[i] = ELTVIDE; // tous les éléments de la pile sont initialisés
    }
    p.dateEntStock=0 ;
    return p;
}

void vider2(produit *adrPile){
    while (adrPile->dateEntStock >=0){
        adrPile->reference[adrPile->dateEntStock-1] = ELTVIDE;
        (adrPile->dateEntStock)-- ;
    }
}

char sommet(produit p) { // la pile est un paramètre d’entrée
    char elt;
    if (!(estVide(p))) {
        // le sommet de la pile est à l’indice p.dateEntStock - 1
        elt = p.reference[p.dateEntStock-1];
    }
    else{
        elt = ELTVIDE;
    }
    return elt;
}

estPleine(produit p){
    return (p.dateEntStock==MAX);
}

int estVide(produit p){
return (p.dateEntStock == 0);
}
