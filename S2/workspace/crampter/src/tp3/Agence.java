package tp3;

import java.util.ArrayList;
import java.util.Scanner;

public class Agence{
	private ArrayList<Voiture> parc;
	private ArrayList<Client> clientele;
	private ArrayList<Location> liste;
	Scanner scan = new Scanner(System.in);
	Agence(){
		
		parc = new ArrayList<Voiture>();
		clientele=new ArrayList<Client>();
		liste = new ArrayList<Location>();
		Client client1=new Client("jean" ,"clanche");
		Client client2=new Client("jean" ,"pal");
		Client client3=new Client("jean" ,"neymar");
		this.clientele.add(client1);
		this.clientele.add(client2);
		this.clientele.add(client3);
		
		Voiture voiture1=new Voiture("caca", "caca", 100, 30);
		Voiture voiture2=new Voiture("pipi", "pipi", 400, 10);
		Voiture voiture3=new Voiture("ouou", "ouou", 200, 20);
		this.parc.add(voiture1);
		this.parc.add(voiture2);
		this.parc.add(voiture3);
	}

	
	public String toString() {
		return ""+liste;
	}
	
	
	public void enregistrer(){
		int numClient;
		int e=0;
		int i=0;
		String immatriculation;
		System.out.println("Numéro client");
		numClient=scan.nextInt();
		while(clientele.get(i).getId()!=numClient) {
			i++;
			if(i>=clientele.size()) {
				i=0;
				System.out.println("erreur\nclientele");
				numClient = scan.nextInt();
			}
		}
		for(int z=0; z<parc.size();z++) {
			System.out.println(parc.get(z));
		}
		System.out.println("immatriculation");
		immatriculation = scan.next();
		while(parc.get(e).getImmatriculation().compareTo(immatriculation)!=0) {
			e++;
			if(e>=parc.size()){
				e=0;
				System.out.println("erreur\nimmatriculation");
				immatriculation = scan.next();
			}
		}
		Date date=new Date();
		Location location=new Location(parc.get(e), clientele.get(i), date);
		liste.add(location);
	}

	public void enregistrerRetour(){
		int e=0;
		int i=0;
		int kilometrage;
		int distance;
		float prix;
		String immatriculation;
		System.out.println("immatriculation");
		immatriculation = scan.next();
		while (liste.get(e).getVoiture().getImmatriculation()!=immatriculation) {
			e++;
			if(e>=liste.size()){
				e=0;
				System.out.println("erreur\nimmatriculation");
				immatriculation = scan.next();
			}
		}
		System.out.println(liste.get(e));
		Date date=new Date();
		liste.get(e).setDateRetour(date);
		System.out.println("kilometrage");
		kilometrage=scan.nextInt();
		if(kilometrage<liste.get(e).getVoiture().getNbKm()) {
			System.out.println("erreur\nkilometrage");
			kilometrage=scan.nextInt();
		}
		distance=kilometrage-liste.get(e).getVoiture().getNbKm();
		prix=distance*liste.get(e).getVoiture().getTarifAuKm();
		System.out.println("prix: "+prix);
		liste.get(e).setDateRetour(date);
		liste.get(e).getVoiture().setNbKm(kilometrage+liste.get(e).getVoiture().getNbKm());
	}
}