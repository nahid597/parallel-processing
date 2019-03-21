package ru.ac.bd;

import java.rmi.Naming;

public class Client {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		AddTwoNumbers obj = (AddTwoNumbers) Naming.lookup("rmi://localhost:1900" + "/server1");
		AddTwoNumbers obj2 = (AddTwoNumbers) Naming.lookup("rmi://localhost:1901" + "/server2");
		    
		   int sum1 = obj.AddTowNum(5, 6);
		   int sum2 = obj2.AddTowNum(6, 8);
		   
		   int sum = sum1 + sum2;
		   
		   System.out.println("result is: " + sum);
	}

}
