
import java.util.*;
import java.math.*;

public class J03035 {
    public static long res = 0;
    public static boolean ok = false, ok2 = true;
    public static StringBuilder s, t;

    public static void back_track(int i) {
        if (!ok2) return;
        if (i > (s.length() - 1)) {
            return;
        }
        if (s.charAt(i) != '?') {
            if (i == s.length() - 1) {
                if (s.toString().compareTo(t.toString()) > 0) {
                    res++;
                    return;
                }
            }
            if (s.charAt(i) < t.charAt(i)) {
                if (!ok) {
                    ok2 = false;
                    return;
                } else back_track(i + 1);
            } else {
                ok = true;
                back_track(i + 1);
            }
        } else {
            for (char c = '0'; c <= '9'; c++) {
                s.setCharAt(i, c);
                if (i == s.length() - 1) {
                    if (s.toString().compareTo(t.toString()) > 0) res++;
                } else back_track(i + 1);
                s.setCharAt(i, '?');
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long T = sc.nextLong();
        sc.nextLine();
        while (T-- > 0) {
            s = new StringBuilder(sc.nextLine());
            t = new StringBuilder(sc.nextLine());
            back_track(0);
            System.out.println(res);
            res = 0;
            ok = false;
            ok2 = true;
        }
    }
}
