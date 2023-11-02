import java.util.*;

public class J03031 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTests = sc.nextInt();
        sc.nextLine(); // Consume the newline character
        
        for (int i = 0; i < numTests; i++) {
            String s = sc.next();
            int k = sc.nextInt();
            boolean canBeComplete = isCompleteStringPossible(s, k);
            if (canBeComplete) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        sc.close();
    }
    
    public static boolean isCompleteStringPossible(String s, int k) {
        if (k >= s.length()) {
            return true;
        }
        
        Set<Character> uniqueChars = new HashSet<>();
        for (char c : s.toCharArray()) {
            uniqueChars.add(c);
        }
        
        return uniqueChars.size() >= 26 || k >= 26 - uniqueChars.size();
    }
}
