package tp3;

public class Location{
	private static int count=1;
	private int numero;
	private Voiture voiture;
	private Client client;
	private Date dateLoca;
	private Date dateRetour;
	private int km;
	Location(Voiture voiture, Client client, Date dateLoca){
		this.numero=count++;
		this.voiture=voiture;
		this.client=client;
		this.dateLoca=dateLoca;
		this.dateRetour=null;
		this.km=voiture.getNbKm();
	}
	
	public String toString(){
		String fin;
		if(this.dateRetour==null) {
			fin="\nNuméro: "+this.numero+"\nClient: "+this.client+"\nDate de location: "+this.dateLoca+"\nDate de retour: Pas de date "+"\nkm: "+km+"\n";
					
		
					
		}else { 
			fin="\nNuméro: "+this.numero+"\nClient: "+this.client+"\nDate de location: "+this.dateLoca+"\nDate de retour: "+this.dateRetour+"\nkm: "+km+"\n";
		}
		return fin;
	}

	public Date getDateRetour() {
		return dateRetour;
	}

	public void setDateRetour(Date dateRetour) {
		this.dateRetour = dateRetour;
	}
	
	
}