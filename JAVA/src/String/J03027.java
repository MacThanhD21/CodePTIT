import java.util.*;

public class J03027 {
    public static String removedString(String s){
        StringBuilder sb = new StringBuilder();

        for(char x : s.toCharArray()){
            int len = sb.length();
            if(len > 0 && sb.charAt(len - 1) == x){
                sb.deleteCharAt(len - 1);
            }
            else{
                sb.append(x);
            }
        }

        if(sb.length() == 0){
            return "Empty String";
        } else {
            return sb.toString();
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();

        String ans = removedString(s);

        System.out.println(ans);
    }
}