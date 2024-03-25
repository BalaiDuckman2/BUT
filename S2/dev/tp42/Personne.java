public class Personne {
    private String nom;
    private String prenom;
    private String adresse;

    Personne(String nom, String prenom, String adresse){
        this.nom=nom;
        this.prenom=prenom;
        this.adresse=adresse;
    }
    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public String getAdresse() {
        return adresse;
    }

    public void setAdresse(String adresse) {
        this.adresse = adresse;
    }
    
    public String toString() {
        return "Nom: "+this.nom+"\nPrenom: "+this.prenom+"\nAdresse: "+this.adresse;
    }

    public void affiche(){
        System.out.println(this.toString());
    }
    
}
