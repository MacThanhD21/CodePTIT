import java.util.*;
import java.math.*;

public class J01024 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long T = Long.parseLong(sc.nextLine());
        while(T-- > 0)
        {
            boolean ok = true;
            String s = sc.nextLine();
            for(char x : s.toCharArray())
            {
                if(x!='0' && x!='1' && x!='2')
                {
                    ok=false;
                    break;
                }
            }
            if(ok) System.out.println("YES");
            else System.out.println("NO");
        }

    }
}

