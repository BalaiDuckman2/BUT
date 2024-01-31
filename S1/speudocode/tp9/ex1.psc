constante entier NB_LIG := 5;
constante entier NB_COL := 10;
type t_tablo = tableau[NB_LIG,NB_COL] de entier;
procédure saisir(sortF tab t_tablo) c'est
début
    lig,col : entier
    val : entier
    pour (lig de 1 à NB_LIG) faire
        pour (col de 1 à NB_COL) faire
            affiche("saisir la valeur(",lig,";",col,")");
            lire(val);
            tab[lig][col]:=vol; 
        finfaire
    finfaire
fin
procédure affiche(sortF tab t_tablo) c'est
début
    lig, col : entier
    pour (lig de 1 à NB_LIG) faire 
        pour col de 1 à NB_COL faire
            affiche(tab[lig][col],"|");
        finfaire
        afiiche("\n")
    finfaire

fin
