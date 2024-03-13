public abstract class Bateau {
    String nom;
    int poids;
    String port;
    int longueur;

    public Bateau(String nom, int poids, String port, int longueur) {
        this.nom = nom;
        this.poids = poids;
        this.port = port;
        this.longueur = longueur;
    }
    abstract int taxe();

    public String toString() {
        return "Nom: " + nom + " Poids: " + poids + " Port: " + port + " Longueur: " + longueur;
    }

    public void afficher() {
        System.out.println(toString());
    }
}
