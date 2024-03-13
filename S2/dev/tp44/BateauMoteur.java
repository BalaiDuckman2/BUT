public class BateauMoteur extends Bateau{
    private int puissance;

    public BateauMoteur(String nom, int poids, String port, int longueur, int puissance) {
        super(nom, poids, port, longueur);
        this.puissance = puissance;
    }

    public int taxe(){
        return 70*this.longueur + 5*this.puissance;
    }

    public String toString() {
        return super.toString() + " Puissance: " + puissance;
    }
}
