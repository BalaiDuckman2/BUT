#include <stdio.h>
#include <stdlib.h>

const char AUTEUR[] = "Julien Le Bihan";
const char MATIERE[] = "Algorithme et Programmation";
const char EXERCICE[] = "Introduction aux procedures";

void afficher(const char nom[60], const char prenom[60], const char exercice[60]);

int main() {
    afficher(AUTEUR, MATIERE, EXERCICE);

    return EXIT_SUCCESS;
}



void afficher(const char nom[60], const char prenom[60], const char exercice[60]) {
    printf("%s\n", nom);
    printf("%s\n", prenom);
    printf("%s\n", exercice);
}
