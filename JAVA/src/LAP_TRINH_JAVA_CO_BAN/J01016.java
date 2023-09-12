
import java.util.Scanner;

public class J01016 {
    
    public static boolean check(long n){
        int so_4 = 0;
        int so_7 = 0;
        while(n > 0){
            long res = n % 10;
            if(res == 4) ++so_4;
            else if(res == 7) ++so_7;
            n /= 10;
        }
        if(so_4 + so_7 == 4 || so_4 + so_7 == 7) return true;
        else return false;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if(check(n) == true) System.out.println("YES");
        else System.out.println("NO");
    }
}
