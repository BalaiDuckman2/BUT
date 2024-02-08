# coding: utf-8
""" 
Une classe Python pour creer et manipuler des graphes
"""


class Graphe(object):

    def __init__(self, graphe_dict=None):
        """ initialise un objet graphe.
	    Si aucun dictionnaire n'est
	    créé ou donné, on en utilisera un 
	    vide
        """
        if graphe_dict == None:
            graphe_dict = dict()
        self._graphe_dict = graphe_dict

    def aretes(self, sommet):
        """ retourne une liste de toutes les aretes d'un sommet"""
        return self._graphe_dict[sommet]

    def all_sommets(self):
        """ retourne tous les sommets du graphe """
        return list(self)   

    def all_aretes(self):
        """ retourne toutes les aretes du graphe """
        a = list(self)
        
        for i in range(5):
            a[i]=self.aretes(a[i])
            
        return(a)

    def add_sommet(self, sommet):
        """ Si le "sommet" n'set pas déjà présent
	dans le graphe, on rajoute au dictionnaire 
	une clé "sommet" avec une liste vide pour valeur. 
	Sinon on ne fait rien.
        """
        a=list(self)
        fin = int(0)
        for i in range(5):
            if sommet == a[i]:
                fin =1
        if fin==0:
            self._graphe_dict[sommet]={}

    def add_arete(self, arete):
        """ l'arete est de  type set, tuple ou list;
            Entre deux sommets il peut y avoir plus
	    d'une arete (multi-graphe)
        """
        dep,arr =arete
        if dep in self.all_sommets():
            if arete not in self.all_aretes():
                self._graphe_dict[dep].append(arr)


    def __list_aretes(self):
        """ Methode privée pour récupérer les aretes. 
	    Une arete est un ensemble (set)
            ave.c un (boucle) ou deux sommets.
        """
        a = list(self)
        
        for i in range(5):
            a[i]=self.aretes(a[i])
            
        return(a)
    
    def __iter__(self):
        self._iter_obj = iter(self._graphe_dict)
        return self._iter_obj

    def __next__(self):
        """ Pour itérer sur les sommets du graphe """
        return next(self._iter_obj)

    def __str__(self):
        res = "sommets: "
        for k in self._graphe_dict.keys():
            res += str(k) + " "
        res += "\naretes: "
        for arete in self.__list_aretes():
            res += str(arete) + " "
        return res
    
    def trouve_chaine(self, sommet_dep, sommet_arr, chain=None):
        if sommet_arr == sommet_dep :
            return chain+sommet_arr
        elif chain ==None:
            chain = sommet_dep
        else:
            chain = chain + sommet_dep
        for i in self.all_sommets():
            if i in self.aretes(sommet_dep) and i not in chain:
                return self.trouve_chaine(i,sommet_arr,chain)

    def trouve_tous_chemins(self, sommet_dep, sommet_arr, chem=[]):
        res = []
        
        if sommet_dep == sommet_arr:
            return [[sommet_arr]]
        else:
            for voisin in self.aretes(sommet_dep):
                if (voisin not in chem):
                    sous_chaines = self.trouve_tous_chemins(voisin,sommet_arr,chem + [voisin])
                    for chaine in sous_chaines:
                        res.append([sommet_dep] + chaine)
            
            return res



class Graphe2(Graphe):
    def sommet_degre(self, sommet):
        """ renvoie le degre du sommet """
        return degre
    
    
    def trouve_sommet_isole(self):
        """ renvoie la liste des sommets isoles """
        return isoles
    
    def Delta(self):
        """ le degre maximum """
        return max
    
    def list_degres(self):
        """ calcule tous les degres et renvoie un
        tuple de degres decroissant
        """
        return degres
        
        
g= graphe = {"A" :["C"],
"B" : ["C", "E"],
"C" : ["A", "B", "D", "E"],
"D" : ["C"],
 "E" : ["C", "B"],
"F" : set()
}
g2=Graphe(g)
print(g2.trouve_tous_chemins("A","E"))

