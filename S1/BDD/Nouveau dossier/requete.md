/* 1.Quels sont les noms des produits commercialisés par l’entreprise ? */
PRODUIT{NOMP}

/* 2.Quels sont les produits originaires de ’Dijon’ ? */
    PRODUIT WHERE ORIGINE = DVILLE('Dijon')

/* 3.Quels sont les noms des produits originaires de ’Dijon’ ? */
(PRODUIT WHERE ORIGINE = DVILLE ('Dijon'))
{NOMP}

/* 4.Quels sont les numéros des fournisseurs qui fournissent quelque chose ? */
FOURNITURE{NOFOUR}

/* 5.Quels sont les numéros des fournisseurs qui ne fournissent rien ? 
Différence après projection */

FOURNISSEUR{NOFOUR}
MINUS
FOURNITURE{NOFOUR}

/* 6.Quels sont les numéros des fournisseurs qui fournissent au moins le produit ’P6’ ? */
(FOURNITURE WHERE NOPRODUIT = DNOPROD('P6'))
{NOFOUR}

/* 7.Quels sont les numéros des fournisseurs qui fournissent quelque chose d’autre que ’P6’ ? */
(FOURNITURE WHERE NOPRODUIT <> DNOPRODUIT('P6'))
{NOFOUR}

/* 8.Quels sont les numéros des fournisseurs qui ne fournissent pas ’P6’ ? */
FOURNISSEUR{NOFOUR}
MINUS
(FOURNITURE WHERE NOPRODUIT = DNOPRODUIT('P6'))
{NOFOUR}

/* 9.Quels sont les numéros des fournisseurs qui fournissent quelque chose mais pas ’P6’ ? */
FOURNITURE{NOFOUR}
MINUS
(FOURNITURE WHERE NOPRODUIT = DNOPRODUIT('P6'))
{NOFOUR}

/* 10.Quels sont les numéros des Fournisseurs qui ne fournissent que ’P6’ ? */
FOURNITURE{NOFOUR}
MINUS
(FOURNITURE WHERE NOPRODUIT <> DNOPRODUIT('P6'))
{NOFOUR}

/* 11.Quels sont les numéros des fournisseurs qui fournissent ’P4’ ou ’P6’ ? */
(FOURNITURE WHERE NOPRODUIT = DNOPRODUIT('P4') 
    OR NOPRODUIT = DNOPRODUIT('P6'))
{NOFOUR}

/* 12.Quels sont les numéros des fournisseurs qui fournissent ’P4’ et ’P6’ ? */
(FOURNITURE WHERE NOPRODUIT = DNOPRODUIT('P4')){NOFOUR}
INTERSECT
(FOURNITURE WHERE NOPRODUIT = DNOPRODUIT('P6)){NOFOUR}

/* 13.Quels sont les numéros des fournisseurs qui ne fournissent ni ’P4’ ni ’P6’ ? */
FOURNISSEUR{NOFOUR}
MINUS
(FOURNITURE WHERE NOPRODUIT = DNOPRODUIT('P6') 
    OR FOURNITURE WHERE NOPRODUIT = DNOPRODUIT('P4'))
{NOFOUR}

/* 14.Quels sont les numéros et noms des fournisseurs qui fournissent ’P6’ ? */
(
    (FOURNISSEUR JOIN FOURNITURE)
    WHERE NOPRODUIT = DNOPRODUIT('P6')
)
{NOFOUR,NOMF}

/* 15.Quels sont les numéros et noms des fournisseurs qui ne fournissent ni ’P4’ ni ’P6’ ? */
FOURNISSEUR{NOFOUR,NOMF}
JOIN
(FOURNISSEUR{NOFOUR}
MINUS
    (FOURNITURE WHERE NOPRODUIT = DNOPRODUIT('P4')
    OR NOPRODUIT = DNOPRODUIT('P6'))
{NOFOUR})

/* 16.Quels sont les numéros,noms et villes des fournisseurs qui fournissent au moins un produit originaire de leur ville ? */
((FOURNISSEUR JOIN FOURNITURE JOIN PRODUIT)
WHERE VILLE = ORIGINE) {NOFOUR, NOMF, VILLE}

/* 17.Quels sont les produits qui sont de même couleur ? Le résultat sera présenté par des couples de numéros de produits. */


/* 18.Quels sont les produits de même couleur que la salade (certaines salades sont rouges, d’autres vertes ...) ? */


/* 19.Quels sont les numéros des fournisseurs qui fournissent des produits verts ou rouges ? */


/* 20.Quels sont les numéros des fournisseurs qui fournissent des produits verts et rouges ? */


/* 21.Quels sont les numéros des fournisseurs qui fournissent des produits verts et des produits rouges (interdiction d’utiliser */
/* l’opérateur ’intersect’) ? */


/* 22.Quels sont les numéros et noms des fournisseurs qui ne fournissent pas de produit vert ? */


/* 23.Quels sont les numéros et noms des fournisseurs qui ne fournissent que des produits verts ? */


/* 24.Quels sont les numéros et noms des fournisseurs qui ne fournissent que des produits verts ou jaunes ? */