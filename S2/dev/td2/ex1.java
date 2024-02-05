public class ex1 {
    public static void main (String[] args){ 

    }
}

class Domino {
    int g;
    int d;
    int contient;
    Domino(int g, int d){
        this.g = g;
        this.d = d;
    }
    void afficher(){
        System.out.println(this.g);
        System.out.println(this.d);

    }

    void inverser(){
        contient = this.g;
        this.g = this.d;
        this.d = contient;
    }
    
    int laGauche(){
        return this.g;
    }
 
    int laDroite(){
        return this.d;
    }
}