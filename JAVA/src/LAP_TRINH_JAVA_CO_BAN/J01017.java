import java.util.*;
import java.math.*;

public class J01017 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long T = sc.nextLong();
        sc.nextLine();
        while(T-- > 0)
        {
            boolean ok = true;
            String s = sc.nextLine();
            for(int i=1;i<s.length();i++)
            {
                if(Math.abs(s.charAt(i)-s.charAt(i-1))!=1)
                {
                    ok = false;
                    break;
                }
            }
            if(ok) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}

