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
        boolean fin = false;
        while (fin==false) {
            if (5<(dateJ-laPile.sommet().date)) {
                laPile.depiler();
            }else{
                fin=false;
                System.out.println(laPile.sommet());
            }
        }
    }

    void afficheMenu(){
        Stock leStock = new Stock(10)
        Scanner scan = new Scanner(System.in)
        Produit prod;
        String choix;
        System.out.println("e : entrée d’un produit dans le stock ; ");
        System.out.println("s : sortie d’un produit du stock ; ");
        System.out.println("i : incrémenter la date du jour ; ");
        System.out.println("q : quitter. ");
        choix =scan.next();
        while (choix!="q") {
            if (choix=="e") {
                leStock.entrer(prod);
                leStock.sommet()
            }else if (choix=="s") {
                leStock.sortir(date);
            }else if (choix=="i") {
                leStock.date++;
            }
            System.out.println("e : entrée d’un produit dans le stock ; ");
            System.out.println("s : sortie d’un produit du stock ; ");
            System.out.println("i : incrémenter la date du jour ; ");
            System.out.println("q : quitter. ");
            choix =scan.next();
        }
        
    }
}
