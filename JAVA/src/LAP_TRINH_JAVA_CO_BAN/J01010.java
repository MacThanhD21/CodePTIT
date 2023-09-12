import java.util.*;
import java.math.*;

public class J01010 {
    public static void solve(String s)
    {
        StringBuilder t = new StringBuilder(s);
        for(int i=0;i<t.length();i++)
        {
            if(t.charAt(i)=='8' || t.charAt(i)=='9') t.setCharAt(i,'0');
            else if(t.charAt(i)=='1' || t.charAt(i)=='0') continue;
            else
            {
                System.out.println("INVALID");
                return;
            }
        }
        while(t.length()>0 && t.charAt(0)=='0')
        {
            t.delete(0,1);
        }
        if(t.length()==0)
        {
            System.out.println("INVALID");
            return;
        }
        System.out.println(t.toString());
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long T = Long.parseLong(sc.nextLine());
        while(T-- > 0)
        {
            String s = sc.nextLine();
            if(s.length()==0) System.out.println("INVALID");
            else solve(s);
        }
    }
}

