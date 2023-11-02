
import java.util.Scanner;

public class J03021 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        scanner.nextLine();

        while (T-- > 0) {
            String message = scanner.nextLine();
            if (isPalindrome(message)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    public static boolean isPalindrome(String message) {

        String num = "";
        for (Character x : message.toCharArray()) {
            num += getDigit(x);

        }
        StringBuilder sb = new StringBuilder(num);
        return sb.reverse().toString().equals(num);
    }

    public static int getDigit(char c) {
        switch (c) {
            case 'A':
            case 'B':
            case 'C':
            case 'a':
            case 'b':
            case 'c':
                return 2;
            case 'D':
            case 'E':
            case 'F':
            case 'd':
            case 'e':
            case 'f':
                return 3;
            case 'G':
            case 'H':
            case 'I':
            case 'g':
            case 'h':
            case 'i':
                return 4;
            case 'J':
            case 'K':
            case 'L':
            case 'j':
            case 'k':
            case 'l':
                return 5;
            case 'M':
            case 'N':
            case 'O':
            case 'm':
            case 'n':
            case 'o':
                return 6;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'p':
            case 'q':
            case 'r':
            case 's':
                return 7;
            case 'T':
            case 'U':
            case 'V':
            case 't':
            case 'u':
            case 'v':
                return 8;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                return 9;
            default:
                return -1; // Không phải ký tự hợp lệ
        }
    }
}
