#include <stdio.h>

int main() {
    char periode;
    int nbEnfants, nbAdultes;
    double tarifEnfant, tarifAdulte, prixTotal;

    // Demander à l'utilisateur de saisir la période (A, B, C ou D)
    printf("Entrez la période (A, B, C ou D) : ");
    scanf(" %c", &periode);

    // Demander à l'utilisateur de saisir le nombre d'enfants et d'adultes
    printf("Entrez le nombre d'enfants : ");
    scanf("%d", &nbEnfants);
    printf("Entrez le nombre d'adultes : ");
    scanf("%d", &nbAdultes);

    // Utiliser un switch pour déterminer les tarifs en fonction de la période
    switch (periode) {
        case 'A':
            tarifEnfant = 7.0;
            tarifAdulte = 12.0;
            break;
            print
        case 'B':
            tarifEnfant = 8.0;
            tarifAdulte = 14.0;
            break;
        case 'C':
            tarifEnfant = 9.0;
            tarifAdulte = 16.0;
            break;
        case 'D':
            tarifEnfant = 10.0;
            tarifAdulte = 18.0;
            break;
        default:
            // En cas de période invalide, afficher un message d'erreur et quitter le programme
            printf("Période invalide. Les périodes valides sont A, B, C ou D.\n");
            return 1;
    }

    // Calculer le prix total en fonction du nombre d'enfants et d'adultes
    prixTotal = (nbEnfants * tarifEnfant) + (nbAdultes * tarifAdulte);

    // Afficher le prix total
    printf("Le prix total est de %.2f euros.\n", prixTotal);

    return 0;
}
