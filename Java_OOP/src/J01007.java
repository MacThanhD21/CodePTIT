
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.List;

public class J01007 {
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
        long t = sc.nextInt();
        Fibo();
        while(t-- > 0){
            long n = sc.nextLong();
            if(Arrays.binarySearch(F, n) >= 0) 
                System.out.println("YES");
            else 
                System.out.println("NO");
        }
    }
}
