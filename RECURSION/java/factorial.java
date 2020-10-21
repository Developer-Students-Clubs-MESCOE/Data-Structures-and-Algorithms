    import java.util.*;
    
    class Factorial{  
     static int factor(int n){    
      if (n == 0 || n == 1)    
        return 1;    
      else    
        return(n * factor(n-1));    
     }    
     public static void main(String args[]){  
      int i,fact=1;  
      int number;   
      Scanner sc=new Scanner(System.in);
      number=sc.nextInt();
      fact = factor(number);   
      System.out.println("Factorial of "+number+" is: "+fact);    
     }  
    }  
