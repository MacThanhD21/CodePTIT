import java.util.Scanner;

public class J03024 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = Integer.parseInt(scanner.nextLine());

        while (T-- > 0) {
            String s = scanner.nextLine();
            if (isValidNumber(s)) {
                String result = isSpecialNumber(s);
                System.out.println(result);
            } else {
                System.out.println("INVALID");
            }
        }
    }

    public static boolean isValidNumber(String s) {
        if (!s.matches("[1-9]\\d*")) {
            return false;
        }
        return true;
    }

    public static String isSpecialNumber(String s) {
        int evenCount = 0;
        int oddCount = 0;

        for (char digit : s.toCharArray()) {
            int num = Character.getNumericValue(digit);
            if (num % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        int length = s.length();
        if (length % 2 == 0) {
            if (evenCount > oddCount) {
                return "YES";
            } else {
                return "NO";
            }
        } else {
            if (oddCount > evenCount) {
                return "YES";
            } else {
                return "NO";
            }
        }
    }
}
