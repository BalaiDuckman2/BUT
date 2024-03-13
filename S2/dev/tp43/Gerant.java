public class Gerant extends Employe {
    private int Nb_H_G;

    Gerant(String nom, int age, int Nb_A){
        super(nom, age, Nb_A);
        this.Nb_H_G=30;

    }

    int calculeSalaire(){
        return 5*this.Nb_H_G*(10+this.Nb_A/2);
    }
}
