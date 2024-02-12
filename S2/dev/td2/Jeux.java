import java.util.Scanner;

public class Jeux {
    public static void main (String[] args){ 
        String exit="O";
        int n=28;
        int gauche;
        int droite;
        Table jeux = new Table(n);
        jeux.initTable();
        jeux.affTable(); 
        Scanner scan=new Scanner(System.in);
        while (exit.compareTo("Q")!=0 && jeux.ndp<n) {
            
            System.out.println("\nGauche");
            gauche=scan.nextInt();
            scan.nextLine();
            System.out.println("Droite");
            droite=scan.nextInt();
            scan.nextLine();
            
            if(jeux.recherche(gauche, droite)==-1) {
                jeux.poserAgauche(gauche, droite);
            }else if(jeux.recherche(gauche, droite)==1){
                jeux.poserAdroite(gauche, droite);
            }else{
                System.out.println("impossible");
            }
            jeux.affTable(); 
            System.out.println("\nQuitter");
            exit=scan.next();
        }
        System.out.println("\nFin");
        scan.close();
    }
}
