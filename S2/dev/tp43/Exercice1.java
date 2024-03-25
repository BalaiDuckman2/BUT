
public class Exercice1 {
    public static void main(String[] args) {
        ListeEmployes liste = new ListeEmployes();
        Gerant g = new Gerant("Gerant", 30, 5);
        Ouvrier o1 = new Ouvrier("Ouvrier1", 25, 3);
        Ouvrier o2 = new Ouvrier("Ouvrier2", 30, 20);
        Ouvrier o3 = new Ouvrier("Ouvrier3", 19, 30);
        liste.ajouter(g);
        liste.ajouter(o1);
        liste.ajouter(o2);
        liste.ajouter(o3);
        liste.afficher();
        System.out.println("\n");
        liste.trier();
        liste.afficher();
        System.out.println("\n");
        ListeEmployes resultat = liste.recherche(20, 30);
        resultat.afficher();
    }
    
    
}