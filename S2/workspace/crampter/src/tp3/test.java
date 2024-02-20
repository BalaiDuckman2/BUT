package tp3;


public class test{
	public static void main(String[] args) {
		Agence agence=new Agence();
		
		agence.enregistrer();
		System.out.println(agence);
		agence.enregistrerRetour();
		System.out.println(agence);
	}	
}
