import java.io.File;
import java.io.FileNotFoundException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.math.BigInteger;
import java.util.Scanner;

public class J07003 {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("DATA.in"));
            String s = "";
            if(sc.hasNextLine()) {
                s = sc.nextLine();                
            }
            while(s.length() > 1) {
                String s1 = s.substring(0, s.length() / 2);
                String s2 = s.substring(s.length() / 2);
                BigInteger a = new BigInteger(s1);
                BigInteger b = new BigInteger(s2);

                s = a.add(b).toString();

                System.out.println(s);
                
            }
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(J07003.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
