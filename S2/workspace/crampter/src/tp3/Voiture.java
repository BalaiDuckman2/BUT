package tp3;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Iterator;


public class Voiture {

	public String getImmatriculation() {
		return immatriculation;
	}
	
	public String getModele() {
		return this.modele;
	}
	
	public int getNbKm() {
		return this.nbKm;
	}
	
	public void setNbKm(int nbKm) {
		this.nbKm = nbKm;
	}
	


	
	public float getTarifAuKm() {
		return this.tarifAuKm;
	}
	
    public String toString(){
    	String fin;
    	fin = "\nimmatriculation: "+this.immatriculation+"\nmodele: "+this.modele+"\nnbKm: "+this.nbKm+"\ntarifAuKm: "+this.tarifAuKm+"\n";
    	return fin;
    }

	
	private String immatriculation;
	private String modele;
	private int nbKm;
	private float tarifAuKm;
	Scanner scan=new Scanner(System.in);
	Voiture(){
		System.out.println("immatriculation");
		this.immatriculation=scan.next();
		System.out.println("modele");
		this.modele=scan.next();
		System.out.println("nbKm");
		this.nbKm=scan.nextInt();
		System.out.println("tarifAuKm");
		this.tarifAuKm=scan.nextFloat();
	}
	Voiture(String immatriculation, String modele, int nbKm, float tarifAuKm){
		this.immatriculation=immatriculation;
		this.modele=modele;
		this.nbKm=nbKm;
		this.tarifAuKm=tarifAuKm;
	}
	
	public static void main(String[] args) {
		ArrayList<Voiture> lVoi = new ArrayList<Voiture>();
		for(int i=0;i<2;i++) {
			Voiture voi = new Voiture();
			lVoi.add(voi);
		}
		System.out.println(lVoi);
	}
	
}