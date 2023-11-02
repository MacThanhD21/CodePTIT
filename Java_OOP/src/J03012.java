import java.util.*;
import java.math.*;


public class J03012 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long T = Long.parseLong(sc.nextLine());
        while(T-- > 0)
        {
            BigInteger a = new BigInteger(sc.next());
            BigInteger b = new BigInteger(sc.next());
            System.out.println(a.add(b));
        }
    }
}