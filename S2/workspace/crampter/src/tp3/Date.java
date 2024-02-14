package tp3;

import java.util.Scanner;

 
public class Date{
	private int jour;
	private int mois;
	private int annee;
	Scanner scan = new Scanner(System.in);
	Date(){
		System.out.println("Jour");
		this.jour = scan.nextInt();
		System.out.println("Mois");
		this.mois = scan.nextInt();
		System.out.println("Année");
		this.annee = scan.nextInt();
	}

	public Date(int jour, int mois, int annee) {
		this.jour = jour;
		this.mois = mois;
		this.annee = annee;
	}
	
	public String toString() {
		String fin="\nJour: "+this.jour+"\nMois: "+this.mois+"Année: "+this.annee+"\n";
		return fin;
	}

	public int getJour() {
		return jour;
	}

	public void setJour(int jour) {
		this.jour = jour;
	}

	public int getMois() {
		return mois;
	}

	public void setMois(int mois) {
		this.mois = mois;
	}

	public int getAnnee() {
		return annee;
	}

	public void setAnnee(int annee) {
		this.annee = annee;
	}
	
	
		
}