package td1;



import java.util.Scanner;
import java.lang.StringBuffer;

class ex2{  
    public static void main (String[] args){  
        String ligne;
        int x=0;
        String inverse;
        Scanner entree=new Scanner(System.in);
        System.out.println("Tapez une ligne"); 
        ligne = entree.next();
        StringBuffer sb=new StringBuffer(ligne);
        StringBuffer oui=new StringBuffer(ligne);
        for(int i=sb.length()-1; i>=0;i--){
            oui.setCharAt(x, sb.charAt(i));
            x++;
            
        }
        inverse = oui.toString();
        if (inverse.equals(ligne)==true) {
            System.out.println("oui");
        }else{
            System.out.println("non");
        }
        System.out.println(oui);
        entree.close();
    }
}