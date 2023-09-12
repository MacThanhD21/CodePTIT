
import java.util.Scanner;

public class J02101 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int[][] a = new int[105][105];
            int n = sc.nextInt();
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    a[i][j] = sc.nextInt();
                }
            }
            for(int i = 1; i <= n; i++){
                if(i % 2 == 1){
                    for(int j = 1; j <= n; j++){
                        System.out.print(a[i][j] + " ");
                    }
                }
                else{
                    for(int j = n; j >= 1; j--){
                        System.out.print(a[i][j] + " ");
                    }
                }
            }
            System.out.println("\n");
        }
    }
}
