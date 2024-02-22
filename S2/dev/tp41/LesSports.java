import java.util.ArrayList;

public class LesSports {
    ArrayList<Sport> liste;

    LesSports(){
        liste=new ArrayList<Sport>();
    }

    public void ajout(Sport nouvSport){
        liste.add(nouvSport);
    }

    public void affiche(){
        for(int i=0;i<liste.size();i++){
            System.out.println(liste.get(i));
        }
    }
}
