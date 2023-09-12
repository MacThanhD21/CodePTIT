
import java.util.*;
import java.math.*;

public class J02005 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong(), m = sc.nextLong();
        Set<Long> se1 = new TreeSet<>();
        Set<Long> se2 = new TreeSet<>();
        for (int i = 1; i <= n; i++) {
            long x = sc.nextLong();
            se1.add(x);
        }
        for (int i = 1; i <= m; i++) {
            long x = sc.nextLong();
            se2.add(x);
        }
        se1.retainAll(se2);
        for (long x : se1) System.out.print(x+" ");
    }
}

