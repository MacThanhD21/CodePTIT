

import java.util.*;
public class J02008 {
    public static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static long bcnn(long a, long b) {
        return a / b * gcd(a, b); 
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            long ans1 = 1;
            long ans2 = 0;
            long ans = 0;
            for(long i = 1; i <= n; i++){
                long gc = gcd(ans, i);
                ans = bcnn(ans, i);
            }

            System.out.println(ans);
        }
    }
}
