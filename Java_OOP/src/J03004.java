import java.util.*;

public class J03004 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());

        while (t-- > 0) {
            String s = sc.nextLine();
            String[] arr = s.trim().split("\\s+");

            String res = "";
            for (String x : arr) {
                res += Character.toUpperCase(x.charAt(0));
                for (int j = 1; j < x.length(); j++) {
                    res += Character.toLowerCase(x.charAt(j));
                }
                res += " ";
            }
            res = res.trim();
            System.out.println(res);
        }
    }
}