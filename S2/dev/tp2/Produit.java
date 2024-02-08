import java.util.Scanner;

public class Produit {
    private String reference;
    int date;
    Scanner scan = new Scanner(System.in);

    void afficher(){
        String fin =""+this.date+""+this.reference;
        System.out.println(fin);
    }

    Produit(int date){
        this.date = date;
        System.out.println("ref produit");
        this.reference=scan.next();
    
    }

}
