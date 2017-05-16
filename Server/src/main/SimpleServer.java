package main;

import java.net.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.io.*;

public class SimpleServer {
	public static final int PORT = 6666;
	public static List<Factura> facturi=null;

	public SimpleServer() throws IOException {
		ServerSocket serverSocket = null;
		try {
			facturi=Collections.synchronizedList(new ArrayList<Factura>());
			serverSocket = new ServerSocket(PORT);
			while (true) {
				System.out.println("Asteptam un client!");
				Socket socket= serverSocket.accept();
				
				ClientThread thread = new ClientThread(socket);
				thread.start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally{
			serverSocket.close();
		}
	}
}
