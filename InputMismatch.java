import java.util.*;

public class InputMismatch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean continueInput = true;
        int num1 = 0;
        int num2 = 0;
        while (continueInput) {
            try {
                System.out.print("Enter first integer: ");
                num1 = input.nextInt();
                System.out.print("Enter second integer: ");
                num2 = input.nextInt();
                continueInput = false;
            }
            catch (InputMismatchException ex) {
                System.out.println("Try again. (Incorrect input: two integers are required) ");
                input.nextLine();
            }

            }
        System.out.println( "The sum is " + (num1 + num2));
        }
    }