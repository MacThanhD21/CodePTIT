
import java.math.BigInteger;
import java.util.*;

public class J03016 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());

        while(t-- > 0){
            BigInteger a = new BigInteger(sc.next());

            BigInteger mod = a.mod(new BigInteger("11"));

            if (mod.equals(BigInteger.ZERO)) {
                System.out.println("1");
            } else {
                System.out.println("0");
            }
        }
    }    
}
