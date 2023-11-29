/**
 * représente un programme simple qui 
 * utilise des structures pour stocker 
 * des informations sur des personnes. 
*/


#include <stdio.h>
#include <string.h>

typedef struct {
    char nom[50];  /** Nom de l'étudiant·e */
    char prenom[50]; /** Prénom de l'étudiant·e */
    int age; /** age de l'étudiant·e */
}Personne; /** Structure d'un·e étudiant·e */

#define TAILLE_LISTE 10 /**Taille de la liste de personne*/

void afficherPersonne(struct Personne p) {
    printf("Nom: %s\n", p.nom);
    printf("Prénom: %s\n", p.prenom);
    printf("Âge: %d\n", p.age);
    printf("\n");
}

/**
 * \brief Ajoute 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/
int rechercherPersonneParNom(struct Personne liste[], int taille, char nomRecherche[]) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(liste[i].nom, nomRecherche) == 0) {
            return i;  
        }
    }
    return -1;  
}

int main() {
    struct Personne listePersonnes[TAILLE_LISTE] = {
        {"Doe", "John", 25},
        {"Smith", "Alice", 30},
    };

    printf("Liste des personnes :\n");
    for (int i = 0; i < TAILLE_LISTE; i++) {
        afficherPersonne(listePersonnes[i]);
    }

    char nomRecherche[50];
    printf("Entrez le nom de la personne à rechercher : ");
    scanf("%s", nomRecherche);

    int indiceTrouve = rechercherPersonneParNom(listePersonnes, TAILLE_LISTE, nomRecherche);
    if (indiceTrouve != -1) {
        printf("Personne trouvée à l'indice %d :\n", indiceTrouve);
        afficherPersonne(listePersonnes[indiceTrouve]);
    } else {
        printf("Personne non trouvée.\n");
    }

    return 0;
}
