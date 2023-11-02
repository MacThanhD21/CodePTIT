
import java.util.Scanner;

public class J01006 {
    public static long[] F = new long[94];

    public static void Fibo(){
        F[0] = 0; 
        F[1] = 1;
        for(int i = 2; i <= 93; i++){
            F[i] = F[i - 1] + F[i - 2];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        Fibo();
        while(t-- > 0){
            int n = sc.nextInt();
            System.out.println(F[n]);
        }
    }
}
