import java.math.BigInteger;
import java.util.Scanner;

public class J03015 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String A = sc.next();
        String B = sc.next();

        BigInteger numA = new BigInteger(A);
        BigInteger numB = new BigInteger(B);

        BigInteger ans = numA.subtract(numB);

        System.out.println(ans);
        
        sc.close();
    }
}