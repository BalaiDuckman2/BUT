public class Ouvrier extends Employe {
    private int Nb_H_O;

    Ouvrier(String nom, int age, int Nb_A){
        super(nom, age, Nb_A);
        this.Nb_H_O=35;
    }
    int calculeSalaire(){
        return 4*this.Nb_H_O*(10+this.Nb_A/2);
    }
}
