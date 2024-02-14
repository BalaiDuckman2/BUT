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
		
		Voiture voiture1=new Voiture();
		Voiture voiture2=new Voiture();
		Voiture voiture3=new Voiture();
		this.parc.add(voiture1);
		this.parc.add(voiture2);
		this.parc.add(voiture3);
		
		Date date1=new Date();
		Date date2=new Date();
		Date date3=new Date();
		
		Location location1=new Location(voiture1,client1,date1);
		Location location2=new Location(voiture2,client2,date2);
		Location location3=new Location(voiture3,client3,date3);
		this.liste.add(location1);
		this.liste.add(location2);
		this.liste.add(location3);
	}

	
	public String toString() {
		return "Agence [parc=" + parc + ", clientele=" + clientele + ", liste=" + liste + "]";
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
				e=0;
				System.out.println("erreur\nclientele");
				numClient = scan.nextInt();
			}
		}
		for(int z=0; i<parc.size();i++) {
			System.out.println(parc.get(i));
		}
		System.out.println("immatriculation");
		immatriculation = scan.next();
		while(parc.get(e).getImmatriculation()!=immatriculation) {
			e++;
			if(e>parc.size()) {
				e=0;
				System.out.println("erreur\nimmatriculation");
				immatriculation = scan.next();
			}
		}
		Date date=new Date();
		Location location=new Location(parc.get(e), clientele.get(i), date);
		
	
	
}