
import java.util.*;

public class J02014 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int idex=-1;
            int sum = 0, left = 0;
            int n = sc.nextInt();
            int[] a = new int[n+1];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                sum += a[i];
            }
            for (int i = 0; i < n; i++) {
                sum -= a[i];
                if (sum == left && i != 0 && i != n - 1) {
                    idex=i+1;
                    break;
                }
                left += a[i];
            }
            System.out.println(idex);
        }
    }
}