import java.util.ArrayList;

public class Course {
    private String nom;
    private String dotation;
    ArrayList<ChevalDeCourse> chevaux ;    

    Course(String nom, String dotation){
        this.nom = nom;
        this.dotation = dotation;
        this.chevaux = new ArrayList<ChevalDeCourse>();
    }
    
    Course(){
        this.chevaux = new ArrayList<ChevalDeCourse>();
    }

    public void afficher() {
        System.out.println("Nom: "+this.nom+"\nDotation: "+this.dotation);
        for(int i=0; i<this.chevaux.size(); i++){
            System.out.println(this.chevaux.get(i).toString());
        }
    }
    public boolean chevalPresent(String nom){
        boolean fin=false;
        for(int i=0; i<this.chevaux.size(); i++){
            if(this.chevaux.get(i).getNom().equals(nom)){
                fin= true;
            }
        }
        return fin;
    }
    public void enregistre(ChevalDeCourse cheval){
        if(chevalPresent(cheval.getNom())==false){
            this.chevaux.add(cheval);
        }
    }
    
    public void recherche(String nom){
        for(int i=0; i<this.chevaux.size(); i++){
            if(this.chevaux.get(i).getNom().equals(nom)){
                System.out.println(this.chevaux.get(i).toString());
            }
        }
    }
    
    public int meilleurCote(){
        int max=0;
        for(int i=0; i<this.chevaux.size(); i++){
            if(this.chevaux.get(i).getGains()>max){
                max=this.chevaux.get(i).getGains();
            }
        }
        return max;
    }
}
