import java.util.*;

public class J03025 {

    public static boolean Palimdrome(String s){
        StringBuilder sb = new StringBuilder(s);
        String t = sb.reverse().toString();
        return s.equals(t);
    }
    
    public static String  replacedString(String s){
        for(int i = 0; i < s.length(); i++){
            for(char x = 'a'; x <= 'z'; x++){
                if(s.charAt(i) != x){
                    StringBuilder sb = new StringBuilder(s);
                    sb.setCharAt(i, x);
                    if(Palimdrome(sb.toString())){
                        return "YES";
                    }
                }
            }
        }

        return "NO\n";
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());

        while(t --> 0){
            String s = sc.nextLine();

            String ans = replacedString(s);

            System.out.println(ans);
            ArrayList<String> ar = new ArrayList<>();
            Collections.sort(ar);

        }
    }
}