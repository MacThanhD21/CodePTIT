

import java.util.ArrayList;
import java.util.Scanner;

public class J05060 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        ArrayList<PhuHo> arr = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new PhuHo(i + 1, sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble()));
        }

        for(PhuHo x : arr) {
            System.out.println(x);
        }
    }
}
