#include <stdio.h>
#include <stdlib.h>

int main()
{ 
float prix, tcc, taxe;


printf("prix: ");
scanf("%f",&prix);
printf("TTC en pourcent: ");
scanf("%f" ,&taxe);
tcc= taxe/100*prix;
printf("%5.2f ",tcc);

}