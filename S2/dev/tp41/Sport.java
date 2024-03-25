
public class Sport {
    private int code;
    private String libelle;

    Sport(int code, String libelle){
        this.code=code;
        this.libelle=libelle;
    }

    public String toString() {
        return "code: "+this.code+"\nlibelle: "+this.libelle;
    }
    
    public void affiche(){
        System.out.println(this.toString());
    }

    
}