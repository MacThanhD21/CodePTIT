
import java.util.*;

public class J03019 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        String result = "";

        for(int i = 0; i < s.length() - 1; i++) {
            if(s.charAt(i) >= s.charAt(i + 1)) {
                result += s.charAt(i);
            }
        }
        
        System.out.println(result);

        scanner.close();
    }
}
