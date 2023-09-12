import java.util.Scanner;

public class J03030 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        int steps = 0;
        int consecutiveBCount = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'B') {
                consecutiveBCount++;
            } else {
                // Calculate the number of operations needed to convert consecutive 'B's to 'A's
                steps += (consecutiveBCount + 2) / 3;
                consecutiveBCount = 0;
            }
        }
        
        // If there are consecutive 'B's at the end of the string
        steps += (consecutiveBCount + 2) / 3;

        System.out.println(steps);
    }
}
