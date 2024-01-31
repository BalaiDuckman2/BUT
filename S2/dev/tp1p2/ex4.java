import java.util.Scanner;
import java.lang.Byte;
class test{  
    public static void main (String[] args){ 

    }
}

class Saisir{
    static private String ligne;
    static private Scanner entree=new Scanner(System.in);

    static public int entier(){
        
        System.out.println("Tapez une ligne");
        ligne = entree.next();
        return Integer.parseInt(ligne);
    }
    static public double reeld(){
        System.out.println("Tapez une ligne");
        ligne = entree.next();
        return Double.valueOf(ligne).doubleValue();
    }
    static public float reelf(){

        System.out.println("Tapez une ligne");
        ligne = entree.next();
        return Float.valueOf(ligne).floatValue();
    }
    static public String chaine(){
        System.out.println("Tapez une ligne");
        ligne = entree.next();
        return ligne;
    }
    static public char car(){
        System.out.println("Tapez une ligne");
        ligne = entree.next();
        char caractere = ligne.charAt(0);
        return caractere;
    }
    
}