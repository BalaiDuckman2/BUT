import java.util.Scanner;

class Table{
    private static int n;
    private Domino[] table;
    public int ndp;
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
       scan.nextLine();
       System.out.println("Droite");
       d=scan.nextInt();
       scan.nextLine();
        Domino prDomino = new Domino(g, d);
        table[0] = prDomino;
        this.ndp++;
        
    }

    void affTable(){
        for(int i=0; i<this.ndp;i++){
            this.table[i].afficher();
        }
        
    }

    int recherche(int g, int d){
        int fin;
        if (d==this.table[0].laGauche() || g==this.table[0].laGauche() ){
            fin= -1;
        }else if(g==this.table[this.ndp-1].laDroite() || d==this.table[this.ndp-1].laDroite()){
            fin= 1;
        }else{
            fin= 0;
        }
        return fin;
    }

    void poserAgauche(int g, int d){  
        
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

    void poserAdroite(int g, int d){
        Domino nouveauDomino = new Domino(g, d);
        if (d==this.table[ndp-1].laDroite()) {
            nouveauDomino.inverser();
        }
            this.ndp++;
            this.table[this.ndp-1]= nouveauDomino;
        
    }

    public static void main (String[] args){
        
        int n=28;
        int gauche;
        int droite;
        Table jeux = new Table(n);
        jeux.initTable();
        jeux.affTable(); 
        Scanner scan=new Scanner(System.in);
        while (jeux.ndp!=n) {
            
            System.out.println("Gauche");
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
            
        }
        scan.close();
    }
}
