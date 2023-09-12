import java.util.Scanner;
import java.math.BigInteger;

public class J03016 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt(); // Số lượng bộ test

        for (int t = 0; t < T; t++) {
            String number = scanner.next();
            int result = isDivisibleBy11(number);
            System.out.println(result);
        }
    }

    public static int isDivisibleBy11(String number) {
        BigInteger N = new BigInteger(number);
        return N.mod(BigInteger.valueOf(11)).equals(BigInteger.ZERO) ? 1 : 0;
    }
}
