package main;

import java.net.*;

import org.omg.CORBA.PRIVATE_MEMBER;

import java.io.*;

public class SimpleClient {

	public static void main(String[] args) throws IOException {
		String adresaIP = "127.0.0.1";

		int PORT = 6666;
		
		Socket socket = null;
		PrintWriter out = null;
		BufferedReader in = null;
		String cerere, raspuns;
		
		
		ObjectInputStream inputStream=null;
		ObjectOutputStream objectOutputStream=null;

		try {
			socket = new Socket(adresaIP, PORT);
			
			
			objectOutputStream= new ObjectOutputStream(socket.getOutputStream());
			//inputStream=new ObjectInputStream(socket.getInputStream());
			Factura factura1=new Factura(20, 100);
			System.out.println("Factura de scris "+factura1.toString());
			objectOutputStream.writeObject(factura1);
			
			
			out = new PrintWriter(socket.getOutputStream(), true);
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

			cerere = "Duke";
			out.println(cerere);

			raspuns = in.readLine();
			System.out.println(raspuns);

		} catch (UnknownHostException e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			if (out != null) {
				out.close();
			}
			if (in != null) {
				in.close();
			}
			if (socket != null) {
				socket.close();
			}
		}

	}

}
