import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;

public class J07078 {
    public static void main(String[] args) throws FileNotFoundException{
        // Scanner scanner = new Scanner(System.in);
        Scanner scanner = new Scanner(new File("STRING.in"));

        int numTests = Integer.parseInt(scanner.nextLine());

        for (int t = 0; t < numTests; t++) {
            String s1 = scanner.nextLine();
            String s2 = scanner.nextLine();

            List<Integer> positions = new ArrayList<>();
            int index = -1;

            // indexOf(s, start_index, end_index)
            while ((index = s1.indexOf(s2, index + 1)) != -1) {
                positions.add(index + 1); // Chỉ số bắt đầu từ 1
            }

            if (!positions.isEmpty()) {
                for (int pos : positions) {
                    System.out.print(pos + " ");
                }
                System.out.println();
            }
        }

        scanner.close();
    }
}
