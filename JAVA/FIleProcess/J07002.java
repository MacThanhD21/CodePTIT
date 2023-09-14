
import java.util.*;
import java.io.*;

public class J07002 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("DATA.in"));

        long sum = 0;
        while (sc.hasNextInt()) {
            try {
                int s = sc.nextInt();
                sum += s;
            } catch (NumberFormatException e) {

            }
        }

        System.out.println(sum);
    }
}
