# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// les constantes symboliques
#define MAX_ANNONCES 200
#define MAX_LIGNES 200
#define MAX_CHAMP 100
// les types
typedef char t_lignes[MAX_LIGNES];
typedef char t_champ[MAX_CHAMP];
typedef struct{
        int id;
        t_champ marque;
        t_champ designation;
        int annee;
        int km;
        int prix;

}t_annonce;

typedef struct{
        t_annonce tabAnnonces[MAX_ANNONCES];
        int nb;
}t_stock;



// les constantes
const t_annonce ANNONCE_VIDE ={1,"sans marque","rien",-1,-1,-1};

// les prototypes des fonctions
t_stock initStock();
void lectureTexte1(char nomfichier[],t_stock *adrStrock);
void afficheAnnonces(t_stock stock);

// le programme principal
int main(){
    t_stock stock_auto;
    t_annonce annonce;
    int choix = -1;
    // initialisation des structures
    initStock(&stock_auto);
    // menu
    while(choix != 0){
        printf("---------------------------------------------------------------------\n");
        printf("1 : lire le fichier texte des annonces (pas d'espace dans les champs)\n");
        printf("2 : lire le fichier texte des annonces \n");
        printf("3 : lire le fichier texte des annonces (variables locales)\n");
        printf("4 : afficher les annonces\n");
        printf("5 : afficher les annonces d'une marque\n");
        printf("6 : sauvegarder les annonces dans un fichier binaire\n");
        printf("7 : lire le fichier binaire des annonces\n");
        printf("8 : ajouter une annonce dans le fichier binaire\n");
        printf("9 : supprimer une annonce\n");
        printf("votre choix :");
        scanf("%d", &choix);
        switch(choix){
            case 0: break;
            case 1: 
                    break;
            case 2: 
                    break;
            case 3: 
                    break;
            case 4: 
                    break;
            case 5: 
                    break;
            case 6: 
                    break;
            case 7: 
                    break;
            case 8: 
                    
                    break;
            default: printf("erreur de choix\n");
        }
    }
    return EXIT_SUCCESS;
}

t_stock initStock(){
        t_stock stock;
        for (int i = 0; i < MAX_ANNONCES; i++)
        {
                stock.tabAnnonces[i]=ANNONCE_VIDE;
        }
        stock.nb=0;
        return stock
}
void lectureTexte1(char nomfichier[],t_stock *adrStrock){
        FILE * fit_stock initStock();ch;
        t_lignes
        fich = fopen(nomfichier,"r");
        fread(ligne,MAX_LIGNES,fich);
        fread(ligne,MAX_LIGNES,fich);
        printf("%s\n")
}
void afficheAnnonces(t_stock stock);
