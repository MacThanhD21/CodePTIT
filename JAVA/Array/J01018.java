import java.util.*;
import java.math.*;

public class J01018 {

    public static boolean check(String s) {
        long sum = Character.getNumericValue(s.charAt(0));
        for (int i = 1; i < s.length(); i++) {
            sum += Character.getNumericValue(s.charAt(i));
            if (Math.abs(s.charAt(i) - s.charAt(i - 1)) != 2) {
                return false;
            }
        }
        if (sum % 10 == 0) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long T = sc.nextLong();
        sc.nextLine();
        while (T-- > 0) {
            String s = sc.nextLine();
            if (check(s)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
