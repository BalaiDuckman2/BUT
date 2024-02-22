public class Jockey extends Personne {
    private int poids;
    private int salaire;
    Jockey(String nom, String prenom, String adresse, int poids, int salaire){
        super(nom, prenom, adresse);
        this.poids=poids;
        this.salaire=salaire;
    }
    public String toString() {
        return super.toString() +"\nPoids: "+this.poids+"\nSalaire: "+this.salaire;
    }
}
