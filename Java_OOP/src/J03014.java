import java.util.*;
import java.math.*;

public class J03014 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long T = 1;
        while(T-- > 0)
        {
            BigInteger a = new BigInteger(sc.nextLine());
            BigInteger b = new BigInteger(sc.nextLine());
            System.out.println(a.add(b));
        }
    }
}