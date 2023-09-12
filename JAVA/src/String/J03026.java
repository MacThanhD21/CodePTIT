
import java.util.*;
public class J03026 {

    public static int maxSubStringLen(String str1, String str2){
        int maxLen = -1;

        for(int i = 0; i < str1.length(); i++){
            for(int j = i + 1; j <= str1.length(); j++){
                String tmp = str1.substring(i, j);
                if(!str2.contains(tmp)){
                    maxLen = Math.max(maxLen, tmp.length());
                }
            }
        }
        return maxLen;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());

        while (t --> 0){
            String str1 = sc.nextLine();
            String str2 = sc.nextLine();

            int ans = Math.max(maxSubStringLen(str1, str2), maxSubStringLen(str2, str1));
            System.out.print(ans + "\n");
        }
    }
}
