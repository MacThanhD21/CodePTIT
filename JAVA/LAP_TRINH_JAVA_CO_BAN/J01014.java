import java.util.*;
import java.math.*;

public class J01014 {
    public static Scanner sc = new Scanner(System.in);
    public static void solve()
    {
        long n = sc.nextLong();
        long res = (long)(-(Math.pow(2,62)));
        for(int i=2;i<=Math.sqrt(n);i++)
        {
            if(n%i==0)
            {
                res = Math.max(res,i);
                while(n%i==0)
                {
                    n/=i;
                }
            }
        }
        if(n!=1) res = Math.max(res,n);
        System.out.println(res);
    }
    public static void main(String[] args) {
        long T = sc.nextLong();
        while(T-- > 0)
        {
            solve();
        }
    }
}

