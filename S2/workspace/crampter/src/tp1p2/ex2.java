package tp1p2;



import java.util.Calendar;
import java.util.ArrayList;
class ex2{  
    public static void main (String[] args){  
        Calendar c = Calendar.getInstance();
        //System.out.println(c.get(Calendar.DAY_OF_WEEK));
        //System.out.println(c.get(Calendar.DAY_OF_MONTH));
        //System.out.println(c.get(Calendar.MONTH)+1);
        //System.out.println(c.get(Calendar.YEAR));
        ArrayList<String> listeJoursSemaine = new ArrayList<String>();
        listeJoursSemaine.add("lundi");
        listeJoursSemaine.add("mardi");
        listeJoursSemaine.add("Mercredi");
        listeJoursSemaine.add("Jeudi");
        listeJoursSemaine.add("Vendredi");
        listeJoursSemaine.add("Samedi");
        listeJoursSemaine.add("Dimanche");
        ArrayList<String> listeMois = new ArrayList<String>();
        listeMois.add("Janvier");
        System.out.println(listeJoursSemaine.get(c.get(Calendar.DAY_OF_WEEK)));
        System.out.println(c.get(Calendar.DAY_OF_MONTH));
        System.out.println(listeMois.get(c.get(Calendar.MONTH)));
        System.out.println(c.get(Calendar.YEAR));

    }  
}
