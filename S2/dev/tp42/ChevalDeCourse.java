public class ChevalDeCourse extends Cheval{
    private int gains;
    private Jockey jockey;
    private Entraineur entraineur;
    ChevalDeCourse(String nom, String sexe,String race, int gains, Jockey jockey, Entraineur entraineur){
        super(nom, sexe,race);
        this.gains = gains;
        this.jockey = jockey;
        this.entraineur = entraineur;
    }
    public int getGains() {
        return gains;
    }
    
    public Jockey getJockey() {
        return jockey;
    }
    
    public Entraineur getEntraineur() {
        return entraineur;
    }
    public String toString() {
        return super.toString()+"\nGains: "+this.gains+"\nJockey: "+this.jockey+"\nEntraineur: "+this.entraineur;
    }
    public void afficher() {
        System.out.println(this.toString());
    }
    public void attribuerJockey(Jockey jockey) {
        this.jockey = jockey;
    }
    
}
