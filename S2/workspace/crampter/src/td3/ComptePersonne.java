package td3;



// ComptePersonne

import java.util.*;
class Personne{
	private String nom, prenom, adresse;

	Personne(String nom, String prenom, String adresse) {
		this.nom = nom;
		this.prenom = prenom;
		this.adresse = adresse;
	}
	
	public String toString() {
		return nom+" "+" "+prenom+" "+adresse;
	}
	
	public void afficher() {
		System.out.println(this);
	}
	
	public String getNom() {
		return nom+" "+prenom;
	}
}

class Compte{

	private String numero;
	private Personne titulaire;
	private double solde;
	Scanner scan=new Scanner(System.in);
	Compte(String i, Personne ti){
		this.numero = i;
		this.titulaire = ti;
		this.solde = 0;
	}
	
	public String toString() {
		return "compte numéro : "+numero;
	}
	
	void afficher(){
		System.out.println("compte numéro : "+numero);
		titulaire.afficher();
		System.out.println("compte solde : "+solde);
	}
	
	void ajouterAr(){
		double argent;
		System.out.println("Somme");
		argent=scan.nextDouble();
		this.solde=+argent;
	}

	void retirerAr(){
		double argent;
		System.out.println("Somme");
		argent=scan.nextDouble();
		if (this.solde-argent<0) {
			System.out.println("Impossible");
		}else{			
			this.solde=-argent;
		}
	}

	public static void main(String[] args) {
		Personne oui =new Personne("cram","pté","apa");
		Compte ui =new Compte("o", oui);
		ui.afficher();
	}
}

