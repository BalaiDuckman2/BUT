public class SportCo extends Sport {
    private int nbJoueurs;
    SportCo(int code,String libelle ,int nbJoueurs){
        super(code, libelle);
        this.nbJoueurs=nbJoueurs;
    }
    @Override
    public String toString() {
        return super.toString() +"\nNombre de joeueur"+this.nbJoueurs;
    }
    public void affiche(){
        this.toString();
    }
}
