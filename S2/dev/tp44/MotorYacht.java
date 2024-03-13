public class MotorYacht extends BateauMoteur {
    int nbEquipage;

    public MotorYacht(String nom, int poids, String port, int longueur, int puissance, int nbEquipage) {
        super(nom, poids, port, longueur, puissance);
        this.nbEquipage = nbEquipage;
    }

    public int taxe(){
        return super.taxe() + 20*this.nbEquipage;
    }

    public String toString() {
        return super.toString() + " Nombre d'equipage: " + nbEquipage;
    }
}
