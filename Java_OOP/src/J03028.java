import java.util.Scanner;

public class J03028 {
    public static String rotateString(String s) {
        int rotation = 0;
        for (char c : s.toCharArray()) {
            rotation += (c - 'A');
        }
        rotation %= 26;
        
        StringBuilder rotated = new StringBuilder();
        for (char c : s.toCharArray()) {
            char rotatedChar = (char) (((c - 'A' + rotation) % 26) + 'A');
            rotated.append(rotatedChar);
        }
        return rotated.toString();
    }

    public static String mergeStrings(String s1, String s2) {
        StringBuilder merged = new StringBuilder();
        for (int i = 0; i < Math.min(s1.length(), s2.length()); i++) {
            int rotation = s2.charAt(i) - 'A';
            char mergedChar = (char) (((s1.charAt(i) - 'A' + rotation) % 26) + 'A');
            merged.append(mergedChar);
        }
        return merged.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(sc.nextLine());
        
        for (int t = 0; t < T; t++) {
            String s = sc.nextLine();
            int half = s.length() / 2;
            String s1 = s.substring(0, half);
            String s2 = s.substring(half);

            String res1 = rotateString(s1);
            String res2 = rotateString(s2);

            String result = mergeStrings(res1, res2);
            System.out.println(result);
        }
    }
}
