type t_candidat = structure
debut
    c_nom : chaîne
    c_age : entier
    c_nbVoix : entier
fin

fonction saisie() délivre t_candidat c'est
début
    cand : t_candidat
    écrireEcran("nom.");
    lireClavier(cand.c_nom);
    écrireEcran("age");
    lireClavier(cand.c_age);
    écrireEcran("nb voix");
    lireClavier(cand.c_nbVoix);
    retourne cand
fin

fonction compare(entF c1:t_candidat, entF c2:t_candidat) délivre entier c'est
début
    elu : entier
    //
    si(c1.c_nbvoix > c2.c_nbVoix) ou ((c1.c_nbVoix ==c2.c_nbVoix) et (1c.c_age > c2.c_age))alors
        elu := 1
    sinonsi()
        elu := 1
    sinon()
        eli := 0
    retourne retourne elu;
fin

programme election c'est
début
    cand1 := saisie():
    affciche("second candidat");
    cand2 := saisie();
    gagnant := compare (entE cand1, entE rand2);
    selon gagnant c'est
        quand 1 : affiche(cand1.c_nom,"elu");
        quand -1 : affiche(cand2.c_nom,"élu")
        quand 0 affiche("egalité");
        defaut : affiche("erreur de comparaison")    
fin