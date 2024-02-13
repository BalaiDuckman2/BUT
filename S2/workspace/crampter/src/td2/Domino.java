package td2;



public class Domino {
    private int g;
    private int d;
    int contient;
    Domino(int g, int d){
        this.g = g;
        this.d = d;
    }
    void afficher(){
        System.out.print(this.g+":"+this.d+" ");
        
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

class test{  
    public static void main (String[] args){  
        Domino oui=new Domino(5,6);
        oui.afficher();
        oui.inverser();
        oui.afficher();

        
    }
}