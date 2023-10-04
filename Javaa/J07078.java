import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class J07078 {
    public static void main(String[] args) throws FileNotFoundException{
        // Scanner scanner = new Scanner(System.in);
        Scanner sc = new Scanner(new File("STRING.in"));
        int testCase = Integer.parseInt(sc.nextLine());

        for (int t = 0; t < testCase; t++) {
            String s1 = sc.nextLine();
            String s2 = sc.nextLine();

            List<Integer> positions = findSubstringPositions(s1, s2);

            if (!positions.isEmpty()) {
                for (int pos : positions) {
                    System.out.print((pos + 1) + " "); // Chỉ số bắt đầu từ 1
                }
                System.out.println();
            }
        }

        sc.close();
    }

    public static List<Integer> findSubstringPositions(String s1, String s2) {
        List<Integer> positions = new ArrayList<>();
        int n = s1.length();
        int m = s2.length();

        for(int i = 0; i <= n - m; i++) {
            boolean found = true;
            for(int j = 0; j < m; j++) {
                if(s1.charAt(i + j) != s2.charAt(j)) {
                    found = false;
                    break;
                }
            }
            if(found) {
                positions.add(i);
            }
        }
        return positions;
    }
}
