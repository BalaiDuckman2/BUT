import java.util.ArrayList;

public class ListeEmployes {
    private ArrayList<Employe> liste;
    
    ListeEmployes(){
        liste = new ArrayList<Employe>();
    }

    public void ajouter(Employe e){
        liste.add(e);
    }

    public void trier(){
        for(int i=0;i<liste.size();i++){
            for(int e=i;e<liste.size();e++){
                if(liste.get(i).calculeSalaire() > liste.get(e).calculeSalaire()){
                    Employe conteneur = liste.get(i);
                    liste.set(i, liste.get(e));
                    liste.set(e, conteneur);
                }
            }
        }
    }

    public void afficher(){
        for(int i=0;i<liste.size();i++){
            liste.get(i).affiche();
        }
    }

    public ListeEmployes recherche(int min,int max){
        ListeEmployes resultat = new ListeEmployes();
        for(int i=0;i<liste.size();i++){
            if(liste.get(i).getAge()<=max && liste.get(i).getAge()>=min){
                resultat.ajouter(liste.get(i));
            }
        }

        return resultat;
    }  
}
