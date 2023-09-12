import java.util.ArrayList;
import java.util.Scanner;


public class J01002 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            long ans = (long)n * (n + 1) / 2;
            System.out.println(ans);
        }
    }
}