import java.util.Scanner;

abstract class Stack <T>
{
	protected T S[];
	protected int top;
	protected int capacity;
	
	void push(T item)
	{
		if(!IsFull())
		{
			top++;
			S[top] = item;
		}
	}
	public void Display()
	{
		int t = top;
		System.out.println("\n\nCURRENT STACK CONTENTS (From Top to Bottom) :");
		while(t != -1)
		{
			System.out.println(S[t]);
			t--; 
		}
	}
	public boolean IsFull()
	{
		if(top == capacity-1)
			return true;
		else
			return false;
	}
	public boolean IsEmpty()
	{
		if(top == -1)
			return true;
		else
			return false;
	}
	public int size()
	{
		return top+1;
	}
	
}

class IntStack extends Stack <Integer>
{
	public IntStack(int c)
	{
		capacity = c;
		top = -1;
		S = new Integer[capacity];
	}
	
	public int pop()
	{	
		if(!IsEmpty())
		{
			int a = S[top];
			top--;
			return a;
		}
		return -1;
	}
}
class CharStack extends Stack <Character>
{
	public CharStack(int c)
	{
		capacity = c;
		top = -1;
		S = new Character[capacity];
	}
	
	public char pop()
	{	
		if(!IsEmpty())
		{
			char a = S[top];
			top--;
			return a;
		}
		return '#';
	}
}
class A12
{
	public static void main(String args[])
	{
		int partition,choice,menu;
		int a,b;
		char c;
		boolean status;
		Scanner scan = new Scanner(System.in);
		System.out.println("CHOOSE : 1. INTERGER STACK \t 2. CHARACTER STACK ");
		partition = scan.nextInt();
		if(partition == 1)
		{
			IntStack obj = new IntStack(5); 
	        do
			{

	            System.out.println("\n:: Menu ::");
	            System.out.println("Press 1 to push an element.");
	            System.out.println("Press 2 to pop an element from top of stack.");
	            System.out.println("Press 3 to find the number of elements in stack.");
	            System.out.println("Press 4 to check if the stack is full.");
	            System.out.println("Press 5 to check if the stack is empty.");
	            System.out.println("Press 0 to display the stack.");          
	            menu = scan.nextInt();            
	            switch (menu)
	            {	
	                case 1 : 
	               		System.out.println("Enter the element : ");
	               		a = scan.nextInt();
	                	obj.push(a);                     
	                	break;                          
	            	case 2 : 
	                	a = obj.pop();
	                	System.out.println("Popped element : "+a);                  
	                	break;                         
	            	case 3 : 
	                	System.out.println("Number of elements in the stack = "+ obj.size() +"\n");
	               		break;                                          
	            	case 4 : 
	                	status = obj.IsFull();
	                	if(status)
	                		System.out.println("The stack is full.");
	                	else
	                	    System.out.println("The stack is not full.");
						break;
	            	case 5 : 
	            	    status = obj.IsEmpty();
	                	if(status)
	                		System.out.println("The stack is empty.");
	                	else
	                	    System.out.println("The stack is not empty.");
	            	    break;        
	            	case 0 :
	            		obj.Display();
	            		break;                 
	            	default : 
	                	System.out.println("Error : Invalid Entry.\n ");
	                	break;   
	            }          
		        System.out.println("\n\nPress 1 to CONTINUE \t Press 0 to EXIT \t");
				choice = scan.nextInt();                        
			} while (choice == 1);               
    	}
    	else if (partition == 2)
    	{
    		CharStack obj = new CharStack(5); 
	        do
			{

	            System.out.println("\n:: Menu ::");
	            System.out.println("Press 1 to push an element.");
	            System.out.println("Press 2 to pop an element from top of stack.");
	            System.out.println("Press 3 to find the number of elements in stack.");
	            System.out.println("Press 4 to check if the stack is full.");
	            System.out.println("Press 5 to check if the stack is empty.");
	            System.out.println("Press 0 to display the stack.");          
	            menu = scan.nextInt();            
	            switch (menu)
	            {	
	                case 1 : 
	               		System.out.println("Enter the element : ");
	               		c = scan.next().charAt(0);
	                	obj.push(c);                     
	                	break;                          
	            	case 2 : 
	                	c = obj.pop();
	                	System.out.println("Popped element : "+c);                  
	                	break;                         
	            	case 3 : 
	                	System.out.println("Number of elements in the stack = "+ obj.size() +"\n");
	               		break;                                          
	            	case 4 : 
	                	status = obj.IsFull();
	                	if(status)
	                		System.out.println("The stack is full.");
	                	else
	                	    System.out.println("The stack is not full.");
						break;
	            	case 5 : 
	            	    status = obj.IsEmpty();
	                	if(status)
	                		System.out.println("The stack is empty.");
	                	else
	                	    System.out.println("The stack is not empty.");
	            	    break;        
	            	case 0 :
	            		obj.Display();
	            		break;                 
	            	default : 
	                	System.out.println("Error : Invalid Entry.\n ");
	                	break;   
	            }          
		        System.out.println("\n\nPress 1 to CONTINUE \t Press 0 to EXIT \t");
				choice = scan.nextInt();                        
			} while (choice == 1);          
    	}
    	else
    		System.out.println("Error : Invalid Entry.\n ");
    }
}
	