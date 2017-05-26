import java.util.Scanner;
public class Calculator {
	public static void main(String[] args) {
		System.out.println("Welcome to Harambe's Calculator");
		while(true) { 
		System.out.println("Enter in your first value");
	Scanner scan = new Scanner(System.in);
	float num1 = scan.nextFloat();
	System.out.println("Enter in your second value");
	Scanner scan1 = new Scanner(System.in);
	float num2 = scan1.nextFloat();
	float value;
	
	System.out.println("Thank you, now put in the operator");
	    Scanner scan2 = new Scanner(System.in);
		String operator = scan2.nextLine();

	       if(operator.equals("*")){
	        value = num1*num2;
	        System.out.println(value);
	    } else if(operator.equals("+")){
	    	 value = num1+num2;
	    	 System.out.println(value);
	    } else if(operator.equals("-")){
	    	 value = num1-num2;
	    	 System.out.println(value);
	    }else if(operator.equals("/")){
	    	 value = num1/num2;
	    	 System.out.println(value);
	    } else {
	    	System.out.println("Invalid Operator");
	    }
	       System.out.println("Do you want to do another calculation? (Y/N)");
	       Scanner scan3 = new Scanner(System.in);
	   	String exitloop = scan3.nextLine();
	   	if(exitloop.equals("N"))
	   	{
		break;
		}
	scan.close();
	scan1.close();
	scan2.close();
	scan3.close();
	  }
   }
}