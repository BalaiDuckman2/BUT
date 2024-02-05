import java.util.Scanner;
import java.lang.StringBuffer ;


class test{  
    public static void main (String[] args){  
        String ligne;
        int nbasci;
        char lettre;
        Scanner entree=new Scanner(System.in);
        System.out.println("Tapez une ligne"); 
        ligne = entree.next();
        StringBuffer sb=new StringBuffer(ligne);
        for(int i=0; i<sb.length();i++){
            nbasci =sb.charAt(i);
            nbasci= nbasci-'a'+2;
            if (nbasci>=26) {
                nbasci=nbasci%26;
            }
            
            nbasci=nbasci+'a';
            lettre = (char)nbasci;
            sb.setCharAt(i,  lettre);
        }
        ligne=sb.toString();
        System.out.println(ligne);
        entree.close();
    }
}