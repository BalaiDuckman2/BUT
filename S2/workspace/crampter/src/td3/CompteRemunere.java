package td3;



public class CompteRemunere extends Compte  {

    private double taux;
    CompteRemunere(String i, Personne ti,double taux) {
        super(i, ti);
        this.taux=taux;  
    }

    Public

    void versementInt(){
    }

    public static void main(String[] args) {
        Personne oui =new Personne("caze","pté","apa");

        CompteRemunere ui =new CompteRemunere("oui", oui,10);
        ui.afficher();
    }
}
