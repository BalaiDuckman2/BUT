#include <stdio.h>
#include <stdlib.h>

const int ACTION1 = 1;
const int ACTION2 = 2;
const int ACTION0 = 0;

void afficher();

int main() {
    menu();

    return EXIT_SUCCESS;
}



void menu() {
       //déclaration des variables
    int action;
    printf("(1)Faire action 1\n");
    printf("(2)Faire action 2\n");
    printf("(0) Quitter 0\n");
    scanf("%d",&action);

   // saisie des données
    while(action != ACTION0){
        printf("(1)Faire action 1\n");
        printf("(2)Faire action 2\n");
        printf("(0) Quitter 0\n");
        scanf("%d",&action);
        if(action==ACTION1){
            printf("action1\n");

        }
        else if(ACTION2==action){
            printf("action2\n");

        }
        else if (action==ACTION0)
            printf("quitter\n");
        else{
            printf("erreur\n");
        }    
    }
}
