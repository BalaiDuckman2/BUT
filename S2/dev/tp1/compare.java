import java.util.Scanner;

class test{  
    public static void main (String[] args){  
        Float i;
        
        Scanner input = new Scanner(System.in);
        String s1=input.next();
        String s2=input.next();
        
        System.out.println(s1.startsWith(s2));
        System.out.println(s1.endsWith(s2));
        System.out.println(s1.contains(s2));
        

    }  
}
