package ru.ac.bd;

import java.rmi.server.UnicastRemoteObject;

public class AddTwoNumI extends UnicastRemoteObject implements AddTwoNumbers {

	public AddTwoNumI() throws Exception {
		super();
	}
	@Override
	public int AddTowNum(int a, int b) {
		// TODO Auto-generated method stub
		return  a + b;
	}

}
