
import java.util.*;


public class J01026 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());
        while(t--> 0){
            long a = sc.nextLong();

            long res = (long)Math.sqrt(a);

            if(res * res == a){
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }    
}
