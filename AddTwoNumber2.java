package ru.ac.bd;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class AddTwoNumber2 extends UnicastRemoteObject implements AddTwoNumbers {

	protected AddTwoNumber2() throws RemoteException {
		super();
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	@Override
	public int AddTowNum(int a, int b) throws Exception {
		
		return a + b;
	}

}
