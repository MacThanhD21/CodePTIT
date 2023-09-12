
import java.util.Scanner;

public class J01012 {
    
    public static int xuly(int n){
        int ans = 0;
        for(int i = 1; i <= Math.sqrt(n); i++){
            if(n % i == 0){
                if(i * i != n){
                    if(i % 2 == 0 && n / i % 2 == 0) ans += 2;
                    else if(i % 2 == 0 || n / i % 2 == 0) ++ans;
                }
                else{
                    if(i % 2 == 0) ++ans;
                }
            }
        }
        return ans;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            System.out.println(xuly(n));
        }
    }
}
