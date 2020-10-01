import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
public class InputTextFile {
    public static void main(String[] args) throws FileNotFoundException, NumberFormatException {
        double average;
        int sum = 0;
        int parselines = 0;
        int notparselines = 0;

        String st = null;
        File file;
        Scanner sc = null;
        String filename;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter name of input file: ");
        filename = scan.nextLine();
        try {
            file = new File(filename);
            sc = new Scanner(file);
        }
        catch(FileNotFoundException e) {
            System.out.println("Could not find file: " + filename);
        }
        while (sc.hasNextLine()) {
            st=sc.nextLine();
            try {
                int number=Integer.parseInt(st);
                sum=sum+number;
                parselines++;
            }
            catch(NumberFormatException e) {
                System.out.println("Cannot parse " + st + " as an integer.");
                notparselines++;
            }
        }
        System.out.println("Number of parsable lines: " + parselines);
        average = Double.valueOf(sum)/Double.valueOf(parselines);
        System.out.println("Average value: " + average);
        System.out.println("Number of unparsable lines: " + notparselines);
    }
}