import java.util.*;

public class J03005 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());

        while (t-- > 0) {
            String s = sc.nextLine();
            String[] arr = s.trim().split("\\s+");

            String res = "";

            for(int i = 1; i < arr.length; i++){
                res += Character.toUpperCase(arr[i].charAt(0));
                for(int j = 1; j < arr[i].length(); j++){
                    res += Character.toLowerCase(arr[i].charAt(j));
                }
                res += " ";
            }
            res = res.substring(0, res.length() - 1);
            res += ", ";
            for(int i = 0; i < arr[0].length(); i++){
                res += Character.toUpperCase(arr[0].charAt(i));
            }
            System.out.println(res);
        }
    }
}