
import java.util.Scanner;

public class J03022 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = "";
        while (sc.hasNext()) {
            s += sc.next() + " ";
        }

        s = s.toLowerCase();
        s = s.replace('?', '.');
        s = s.replace('!', '.');
        s = s.replace(". ", ".");

        String[] res = s.split("\\.");

        String ans = "";
        for (String tmp : res) {
            ans += Character.toUpperCase(tmp.charAt(0)) + tmp.substring(1) + "\n";
        }
        System.out.println(ans);
        sc.close();
    }
}
