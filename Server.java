package ru.ac.bd;

import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class Server {

	public static void main(String arg[]) throws Exception{
	
		AddTwoNumbers obj = new AddTwoNumI();

		LocateRegistry.createRegistry(1900); 
		
		Naming.rebind("rmi://localhost:1900" + "/server1", obj);
		
		System.out.println("server is running...");
		
	}
}
