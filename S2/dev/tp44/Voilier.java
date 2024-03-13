public class Voilier extends Bateau{
    int surfaceVoile;
    

    public Voilier(String nom, int poids, String port, int longueur, int surfaceVoile) {
        super(nom, poids, port, longueur);
        this.surfaceVoile = surfaceVoile;
        
    }

    public int taxe(){
        return 50*this.longueur;
    }

    public String toString() {
        return super.toString() + " Surface de voile: " + surfaceVoile;
    }
}