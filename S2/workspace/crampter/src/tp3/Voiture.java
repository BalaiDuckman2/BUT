package tp3;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Iterator;


public class Voiture {

	public String getImmatriculation() {
		return immatriculation;
	}
	
	public String getModele() {
		return modele;
	}
	
	public int getNbKm() {
		return nbKm;
	}
	
	public float getTarifAuKm() {
		return tarifAuKm;
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
	
	public static void main(String[] args) {
		ArrayList<Voiture> lVoi = new ArrayList<Voiture>();
		for(int i=0;i<2;i++) {
			Voiture voi = new Voiture();
			lVoi.add(voi);
		}
		System.out.println(lVoi);
	}
	
}