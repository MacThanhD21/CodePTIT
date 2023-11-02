import java.util.Scanner;

public class J03030 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int n = s.length();
        
        int[] dp = new int[n + 1];
        
        // Initialize the DP array
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            // If the current character is 'A', no extra step is needed
            if (s.charAt(i - 1) == 'A') {
                dp[i] = dp[i - 1];
            } else {
                // Either convert the current 'B' to 'A' (1 step) or extend the previous sequence of 'B's
                dp[i] = Math.min(dp[i - 1] + 1, dp[Math.max(i - 2, 0)] + 1);
            }
        }
        
        System.out.println(dp[n]);
    }
}
