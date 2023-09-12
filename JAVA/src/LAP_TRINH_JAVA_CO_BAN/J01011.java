
import java.util.*;
import java.math.*;

public class J01011 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(sc.nextLine());
        while (T-- > 0) {
            long x = sc.nextLong(),y = sc.nextLong();
            sc.nextLine();
            BigInteger a = new BigInteger(""+x);
            BigInteger b = new BigInteger(""+y);
            BigInteger c = a.gcd(b);
            System.out.println(a.divide(c).multiply(b) + " " + c);
        }
    }
}

