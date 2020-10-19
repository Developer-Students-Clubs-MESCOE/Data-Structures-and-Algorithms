import java.util.Scanner;

public class GettingUserInput {
    public static void main(String[] args) {
        
        // Creating scanner object
        Scanner input = new Scanner(System.in);
        
        // Output the prompt
        System.out.println("Enter a floating point value: ");
        
        // enter something.
        double value = input.nextDouble();
        
        //they entered.
        System.out.println("You entered: " + value);
    }
}