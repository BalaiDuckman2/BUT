#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//déclaration des constantes
void calcul();
const char oui = ':';
int main(){
   //déclaration des variables


   // saisie des données
    calcul();


   // traitement des données



   // affichage des résultats



   return EXIT_SUCCESS;
}

void calcul(){
    int op1;
    int op2;
    char op;
    op = '+';
    while (op != oui)
    {
        scanf("%d %c %d",&op1,&op,&op2);
        switch (op){
            case '+':
                op1 = op1 + op2;
                printf("%d\n",op1);
                break;
            case '-':
                op1 = op1 - op2;
                printf("%d\n",op1);
                break;
            case '/':
                if(op2 != 0){
                op1 = op1 / op2;
                printf("%d\n",op1);
                break;
                }
                else{
                    printf("division par ");
                }
            case '*':
                op1 = op1 * op2;
                printf("%d\n",op1);
                break;            
            
            default:
                printf("operateur inconnu");
                printf("%d",op1);
                break;
        }
    }
    
   
}