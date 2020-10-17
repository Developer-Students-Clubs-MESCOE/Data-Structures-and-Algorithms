
import java.util.*;
import java.lang.*;
import java.io.*;

class NumberOfPaths
{
    public static int numberofpaths(int m,int n)
    {
        if(m==1||n==1)
        {
            return 1;
        }
        int a=numberofpaths(m-1,n);
        int b=numberofpaths(m,n-1);
        return a+b;
    }
	public static void main (String[] args) 
	{
	    Scanner sc=new Scanner(System.in);
	    int i=0;
	    int m=sc.nextInt();
	    int n=sc.nextInt();
	    System.out.println(numberofpaths(m,n));
	    i=i+1;
	    }
		
	}
}
