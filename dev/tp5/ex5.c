#include <stdlib.h>
#include <stdio.h>

// déclaration des constantes

void ligneTirets(int n);
void ligneCourante(int n, int l);
void corps(int n);

int main()
{
    int largeur;
    int hauteur;
    
    printf("largeur ?");
    scanf("%d", &largeur);
    while (largeur >50 || largeur<1)
    {
        printf("largeur ?");
        scanf("%d", &largeur);
    } 
    printf("hauteur");
    scanf("%d", &hauteur);
    while (hauteur >50 || hauteur<3)
    {
        printf("hauteur ?");
        scanf("%d", &hauteur);
    } 
    ligneTirets(largeur);
    ligneCourante(hauteur, largeur);
    ligneTirets(largeur);

    return EXIT_SUCCESS;
}

void ligneTirets(int n)
{
    while (n != 0)
    {
        printf("-");
        n = n - 1;
    }
    printf("\n");
}

void ligneCourante(int n, int l)
{
    int espace;
    while (n != 0)
    {
        printf("I");
        espace = l-2;
        while(espace!=0)
        {
            printf(" ");
            espace=espace-1;
        }
        printf("I\n");
        n=n-1;
    }
}