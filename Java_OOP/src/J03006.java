
import java.util.*;

public class J03006 {

    public static boolean beauStr(String s) {
        StringBuilder sb = new StringBuilder(s);
        String reversed = sb.reverse().toString();
        
        if (!s.equals(reversed)) {
            return false;
        }

        for (char digit : s.toCharArray()) {
            // Get value of current character
            int num = Character.getNumericValue(digit);
            if (num % 2 != 0) {
                return false;
            }
        }

        return true;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();
        
        TreeSet<Integer> se = new TreeSet<>();

        for(int i = 0; i < n; i++){
            Integer a = sc.nextInt();
            se.add(a);
        }
        for(int i = 0; i < m; i++){
            Integer a = sc.nextInt();
            se.add(a);
        }
        for(Integer x : se){
            System.out.print(x + " ");
        }
    }
}
