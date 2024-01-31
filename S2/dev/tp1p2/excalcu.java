import java.lang.Math;
import java.util.Scanner;


class calcu{  
    public static void main (String[] args){ 
        double angle;
        char choix;
        choix = Saisir.car();
        while(choix!='Q' || choix!='q'){
            if(choix=='C' || choix=='c'){
                angle = Saisir.reeld();
                angle = Math.cos(angle);
                System.out.println(angle);
            }
            if(choix=='S'|| choix=='s'){
                angle = Saisir.reeld();
                angle = Math.sin(angle);
                System.out.println(angle);
            }
            if(choix=='T' || choix=='t'){
                angle = Saisir.reeld();
                angle = Math.tan(angle);
                System.out.println(angle);
            }
            choix = Saisir.car();
        }
        
    }
}