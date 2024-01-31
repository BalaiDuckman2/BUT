#include <stdlib.h>
#include <stdio.h>

const int MAX_MULTIPLICATION = 9;

void ligne(int m);

int main() {
    int compteur = 0; 

    while (compteur <= MAX_MULTIPLICATION) {
       ligne(compteur);
       printf("\n");
       compteur = compteur+1;
    }

    return EXIT_SUCCESS;
}

void ligne(int m) {
   int compteur1;
   int resulat;
   int multiplicateur;
   multiplicateur = 1; 

   for (compteur1 = 1; compteur1 <= MAX_MULTIPLICATION; compteur1++) {
       resulat = multiplicateur * m;
       printf("%3d \t", resulat);
       multiplicateur++;
   }
}
