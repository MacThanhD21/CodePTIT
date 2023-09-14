
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;

public class J07002 {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DATA.in"));
        long sum = 0;

        while (sc.hasNext()) {
            try {
                int x = Integer.parseInt(sc.next());
                sum += x;
            } catch (NumberFormatException e) {
            }
        }
        System.out.println(sum);
    }
}