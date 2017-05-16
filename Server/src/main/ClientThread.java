package main;

import java.net.*;
import java.io.*;


public class ClientThread extends Thread {
	Socket socket=null;
	ObjectInputStream objectInputStream=null;
	
	public ClientThread(Socket newSocket)
	{
		socket=newSocket;
	}
	
	public void run()
	{
		String cerere, raspuns;
		
		try {
			
			objectInputStream=new ObjectInputStream(socket.getInputStream());
			Factura factura=(Factura) objectInputStream.readObject();
			SimpleServer.facturi.add(factura);
			System.out.println("Object received "+factura);
			
			
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			
			PrintWriter out= new PrintWriter(socket.getOutputStream());
			
			cerere=in.readLine();
			
			System.out.println(cerere);
			
			raspuns= "Hello " + cerere+" !";
			for (Factura factura2 : SimpleServer.facturi) {
				System.out.println(factura2.toString());
			}
			out.println(raspuns);
			out.flush();
			
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				socket.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
		
}
