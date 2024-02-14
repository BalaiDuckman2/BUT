package tp2;



import java.util.Scanner;

public class Stock {
    int date;
    

    private Pile laPile;
    Stock(int taille){
        this.laPile = new Pile(taille);
        this.date = 1;
    }

    void entrer(Produit p){
        laPile.empiler(p);
    }

    void sortir(int dateJ){
  
          if (5>(dateJ-laPile.sommet().gDate())) {
        	    laPile.sommet().afficher();
                laPile.depiler();
                
            }else{
                while(laPile.pileVide()==false) {
                	laPile.sommet().afficher();
                	laPile.depiler();
 
            }
        }
    }

    void afficheMenu(){
        Stock leStock = new Stock(10);
        Scanner scan = new Scanner(System.in);
        
        String choix;
        System.out.println("e : entrée d’un produit dans le stock ; ");
        System.out.println("s : sortie d’un produit du stock ; ");
        System.out.println("i : incrémenter la date du jour ; ");
        System.out.println("q : quitter. ");
        choix =scan.next();
        while (choix.compareTo("q")!=0) {
            if (choix.compareTo("e")==0) {
            	Produit prod=new Produit(date);
                leStock.entrer(prod);
                laPile.afficherStock();
                
            }else if (choix.compareTo("s")==0) {
                leStock.sortir(leStock.date);
            }else if (choix.compareTo("i")==0) {
                leStock.date++;
            }
            System.out.println("e : entrée d’un produit dans le stock ; ");
            System.out.println("s : sortie d’un produit du stock ; ");
            System.out.println("i : incrémenter la date du jour ; ");
            System.out.println("q : quitter. ");
            choix =scan.next();
        }
        scan.close();
        
    }
}
