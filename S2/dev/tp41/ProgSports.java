public class ProgSports {
    public static void main(String[] args) {
        Sport i1=new Sport(1, "CACA");
        Sport i3=new Sport(1, "jj");
        Sport i2=new Sport(1, "hh");
        SportCo e1=new SportCo(6, "PIPI", 4);
        LesSports liste=new LesSports();
        liste.ajout(i1);
        liste.ajout(e1);
        
        liste.ajout(i2);
        liste.ajout(i3);
        liste.affiche();
    }
}
