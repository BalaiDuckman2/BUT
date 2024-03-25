public class Cheval {
    private static int compteur=0;
    private int numero;
    private String nom;
    private String sexe;
    private String race;

    Cheval(String nom, String sexe,String race){
        this.numero=++compteur;
        this.nom=nom;
        this.sexe=sexe;
        this.race=race;
    }
    
    public int getNumero() {
        return this.numero;
    }
    
    public void setNumero(int numero) {
        this.numero = numero;
    }
    
    public String getNom() {
        return this.nom;
    }
    
    public void setNom(String nom) {
        this.nom = nom;
    }
    
    public String getSexe() {
        return this.sexe;
    }
    
    public void setSexe(String sexe) {
        this.sexe = sexe;
    }
    
    public String getRace() {
        return this.race;
    }
    
    public void setRace(String race) {
        this.race = race;
    }
    
    public String toString() {
        return "Numero: "+this.numero+"\nNom: "+this.nom+"\nSexe: "+this.sexe+"\nRace: "+this.race;
    }
    
}


