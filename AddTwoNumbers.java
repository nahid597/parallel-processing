package ru.ac.bd;

import java.rmi.Remote;

public interface AddTwoNumbers extends Remote{
    
	public int  AddTowNum(int a, int b) throws Exception;
}
