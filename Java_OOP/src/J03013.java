import java.util.Scanner;
import java.math.BigInteger;

public class J03013 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(); 
        sc.nextLine(); 

        for (int i = 0; i < T; i++) {
            String X = sc.next(); 
            String Y = sc.next();

            BigInteger bigIntX = new BigInteger(X);
            BigInteger bigIntY = new BigInteger(Y);

            String ans = bigIntX.subtract(bigIntY).abs().toString();
            
            while (ans.length() < Math.max(X.length(), Y.length())) {
                ans = "0" + ans;
            }

            System.out.println(ans);
        }

        sc.close();
    }
}