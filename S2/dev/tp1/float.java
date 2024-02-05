import java.util.Scanner;

class test{  
    public static void main (String[] args){  
        Float i;
        
        Scanner input = new Scanner(System.in);
        String o=input.next();
        i=Float.parseFloat(o);
        i=i+1.1f;
        System.out.println(i);

    }  
}
