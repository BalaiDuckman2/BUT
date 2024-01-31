#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes

void petit(int num1, int num2);

int main(){
   //déclaration des variables
    int numero1;
    int numero2;

    printf("donner un nombres");
    scanf("%d",&numero1);
    printf("donner un nombres");
    scanf("%d",&numero2);
    petit(numero1,numero2);

   return EXIT_SUCCESS;
}

void petit(int numero1, int numero2){
    if (numero1>numero2)
    {
        printf("%d est le plus petit",numero2);
    }else if(numero2>numero1){
        printf("%d est le plus petit",numero1);

    }else if(numero1==numero2){
        printf("les numéro sont pareille");
    }
    
    
    
    

}