public abstract class Employe {
    String nom;
    int age;
    int Nb_A;
    int numero;
    static int count = 0;

    public Employe(String nom, int age, int Nb_A) {
        this.nom = nom;
        this.age = age;
        this.Nb_A = Nb_A;
        this.numero = count++; 
    }
    abstract int calculeSalaire();
    public String toString(){
        return "Nom: "+this.nom+" Age: "+this.age+" Nombre d'années: "+this.Nb_A+" Salaire: "+this.calculeSalaire();
    }
    public void affiche(){
        System.out.println(this.toString());
    }

    public static void main(String[] args) {
        Gerant g = new Gerant("Gerant", 30, 5);
        Ouvrier o = new Ouvrier("Ouvrier", 25, 3);
        System.out.println(g);
        System.out.println(o);
    }
    public String getNom() {
        return nom;
    }

    public int getAge() {
        return age;
    }

    public int getNb_A() {
        return Nb_A;
    }

    public int getNumero() {
        return numero;
        
    }
}