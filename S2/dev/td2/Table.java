import java.util.Scanner;

class Table{
    private static int n;
    private Domino[] table;
    private int ndp;
    Table(int n){
        this.table = new Domino[n];
        this.ndp=0;
    }

    void initTable(){
       int g, d;
       Scanner scan=new Scanner(System.in);
       System.out.println("1er domino");
       System.out.println("Gauche");
       g=scan.nextInt();
       System.out.println("Droite");
       d=scan.nextInt();
        Domino prDomino = new Domino(g, d);
        table[0] = prDomino;
        this.ndp++;
        scan.close();
    }

    void affTable(){
        for(int i=0; i<=this.ndp;i++){
            this.table[i].afficher();
        }
        
    }

    int recherche(int g, int d){
        int fin;
        if (d==this.table[0].laGauche() || g==this.table[0].laGauche() ){
            fin= -1;
        }else if(g==this.table[this.ndp].laDroite() || d==this.table[this.ndp].laDroite()){
            fin= 1;
        }else{
            fin= 0;
        }
        return fin;
    }

    void poserAgauche(int g, int d){  
        if (this.ndp==n) {
            Domino nouveauDomino = new Domino(g, d);
            if (g==this.table[0].laGauche()) {
                nouveauDomino.inverser();
            }
            
            for(int i=this.ndp; i>=0;i--){
                this.table[i+1]=this.table[i];
            }
            this.table[0]=nouveauDomino;
            this.ndp++;
        }
        
    }

    void poserAdroite(int g, int d){
        Domino nouveauDomino = new Domino(g, d);
        if (d==this.table[0].laDroite()) {
            nouveauDomino.inverser();
        }

        if (this.ndp==n) {
            this.ndp++;
            this.table[this.ndp]= nouveauDomino;
        }
    }

    public static void main (String[] args){
        Scanner scan=new Scanner(System.in);
        Table jeux = new Table(28);
        jeux.initTable();
        jeux.affTable(); 
        while (jeux.ndp!=n) {
            int g,d;
            System.out.println("Gauche");
            g=scan.nextInt();
            System.out.println("Droite");
            d=scan.nextInt();
            
            if (jeux.recherche(g, d)==1) {
                jeux.poserAgauche(g, d);
            }else if(jeux.recherche(g, d)==-1){
                jeux.poserAdroite(g, d);
            }else{
                System.out.println("impossible");
            }
            jeux.affTable(); 
        }
        
    }
}
