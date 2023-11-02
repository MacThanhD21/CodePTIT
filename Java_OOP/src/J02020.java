import java.util.Scanner;

public class J02020 {
    public static int cnt = 0;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] combination = new int[K];
        generateCombinations(N, K, 1, combination, 0);
        System.out.println();
        System.out.println("Tong cong co " + cnt + " to hop");
        scanner.close();
    }
    public static void generateCombinations(int N, int K, int start, int[] combination, int index) {
        if (index == K) {
            cnt++;
            for (int num : combination) {
                System.out.print(num);
            }
            System.out.print(" ");
            return;
        }
        
        for (int i = start; i <= N; i++) {
            combination[index] = i;
            generateCombinations(N, K, i + 1, combination, index + 1);
        }
    }
}
