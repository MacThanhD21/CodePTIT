import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.math.*;

public class HELLOFILE {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("Hello.txt"));
        while(sc.hasNextLine())
        {
            String s = sc.nextLine();
            System.out.println(s);
        }
    }
}