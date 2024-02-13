package tp2;



public class Voiture {
    private int id;
    private static int count=1;
    private String marque;
    private double vitesse;
    private double puissance;

    Voiture(String marque, double vitesse,double puissance){
        this.marque = marque;
        this.puissance = puissance;
        this.vitesse = vitesse;
        this.id = count++;
        
    }
    Voiture(){
        this.id = count++;
    }

    String gMarque(){
        return this.marque;
    }

    void sMarque(){
        System.out.println("Marque");
        this.marque=Saisir.chaine();
    }
    double gVitesse(){
        return this.vitesse;
    }

    void sVitesse(){
        System.out.println("vitesse");
        this.vitesse=Saisir.reeld();
    }
    double gPuissance(){
        return this.puissance;
    }

    void sPuissance(){
        System.out.println("puissance");
        this.puissance=Saisir.reeld();
    }

    int gId(){
        return this.id;
    }

    void sId(){
        System.out.println("id");
        this.id=Saisir.entier();
    }

    public String toString(){
        String fin = this.id+" "+this.puissance+" "+this.vitesse+" "+this.marque;
        return fin;
    }
    
    
}
