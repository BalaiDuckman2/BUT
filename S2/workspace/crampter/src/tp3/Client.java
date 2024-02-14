package tp3;



public class Client{
	private static int count=1;
	private int id;
	private String nom;
	private String domicile;
	
	Client(String nom, String domicile){
		this.id=count++;
		this.nom=nom;
		this.domicile=domicile;
	}
	
	public String toString() {
		String fin = "\nid: "+this.id+"\nnom: "+this.nom+"\ndomicile: "+this.domicile+"\n";
		return fin;
	}
	
	public static void main(String[] args) {
		Client oui = new Client("az","ba");
		System.out.println(oui);
	}

	public int getId() {
		return id;
	}
	
}