import java.util.Date;
import java.text.SimpleDateFormat;

class test{  
    public static void main (String[] args){  
        Date d = new Date();
        //SimpleDateFormat f=new SimpleDateFormat("dd MMMMM yyyy HH:mm");
        
        SimpleDateFormat f=new SimpleDateFormat("EEEEE DD MMMMMM yyyy HH:mm:ss");
        System.out.println(f.format(d));
    }
}