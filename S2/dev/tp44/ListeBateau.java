import java.util.ArrayList;

public class ListeBateau {
    private ArrayList<Bateau> liste;

    public ListeBateau() {
        liste = new ArrayList<Bateau>();
    }

    public void ajouter(Bateau b) {
        liste.add(b);
    }

    public void afficher() {
        for (int i = 0; i < liste.size(); i++) {
            liste.get(i).afficher();
        }
    }

    public int longueur(String nom){
        int resultat = -1;
        for (int i = 0; i < liste.size(); i++) {
            if (liste.get(i).nom.equals(nom)) {
                resultat =liste.get(i).longueur;
            }
        }
        return resultat;
    }

    public void PortCommun(String port){
        for (int i = 0; i < liste.size(); i++) {
            if (liste.get(i).port.equals(port)) {
                liste.get(i).afficher();
            }
        }
    }
}
