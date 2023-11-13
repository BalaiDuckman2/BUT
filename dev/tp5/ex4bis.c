#include <stdio.h>


void ligne(int m);

int main() {
    int i, j, resultat;


    printf("\nTriangle inférieur gauche :\n");
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= i; j=j+1) {
            resultat = i * j;
            printf("%2d ", resultat );
        }
        printf("\n");
    }

    return 0;
}

void ligne(int m) {
    int i;
    int resultat;
    for (i = 0; i <= 9; i=i+1) {
        resultat= i * m;
        printf("%2d ",resultat );
    }
    printf("\n");
}