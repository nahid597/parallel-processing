package ru.ac.bd;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class Server2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try {
			
			AddTwoNumbers sr2 = new AddTwoNumber2();
			
			LocateRegistry.createRegistry(1901);
			
			try {
				
				Naming.rebind("rmi://localhost:1901" + "/server2", sr2);
				System.out.println("server2 is running...");
				
			} catch (MalformedURLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		

	}

}
