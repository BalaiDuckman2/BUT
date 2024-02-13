package tp2;



public class Pile {
    Produit[] tab;
    int max;
    Pile(int max){
        this.tab = new Produit[max];
        this.max = max;
    }

    boolean pileVide(){
        boolean fin=false;
        if (this.tab[0]==null) {
            fin=true;
        }
        return fin;
    }

    boolean pilePleine(){
        boolean fin=false;
        if (this.tab[this.max-1]==null) {
            fin=true;
        }
        return fin;
    }
    void  empiler(Produit  p){
        int i=0;
        
        if (pilePleine()==true) {
        	
            while (this.tab[i]!=null) {
                i++;
                
            }
            this.tab[i]=p;
            
        }
    }
    void depiler(){
        int i=0;
        if (pileVide()==true) {
            if (pilePleine()==false) {
                while (this.tab[i]!=null) {
                    i++;
                }
                this.tab[i-1]=null;
            }else{
                this.tab[this.max]=null;
            } 
        }
        
    }

    Produit sommet(){
        Produit fin;
        int i=0;
        if(pilePleine()==false){
            fin = this.tab[this.max-1];
        }else{
        
            while(this.tab[i]!=null){
            	
                i++;
            }
            fin =this.tab[i-1];
        }
        return fin;
    }


    void  afficherStock(){
        int i=0;
        if (pilePleine()==false) {
            for(int e=0; e<this.max;e++){
                this.tab[e].afficher();
            }
        }
        while (this.tab[i]!=null) {
            this.tab[i].afficher();
        }
    }
}
