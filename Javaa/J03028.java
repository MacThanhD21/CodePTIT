import java.util.*;
        
public class J03028 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test = 1;
        test = Integer.parseInt(sc.nextLine());

        while(test--> 0){
            String s = sc.nextLine();

            TreeMap<Character, Integer> mp = new TreeMap<>();
        
            for(int i = 0; i < 26; i++) {
                mp.put((char)(i + 65), i);
            }

            // divide
            String s1 = s.substring(0, s.length() / 2);
            String s2 = s.substring(s.length() / 2);

            // Rotate
            long sum1 = 0;
            for(Character c : s1.toCharArray()) {
                if(mp.containsKey(c)) {
                    // System.out.println(c + " " + mp.get(c));
                    sum1 += mp.get(c);
                }
            }
            long sum2 = 0;
            for(Character c : s2.toCharArray()) {
                if(mp.containsKey(c)) {
                    // System.out.println(c + " " + mp.get(c));
                    sum2 += mp.get(c);
                }
            }

            String new_str1 = "";
            String new_str2 = "";

            for(Character c : s1.toCharArray()) {
                long tmp1 = sum1;
                while(tmp1-- > 0) {
                    c++;
                    if (c > 'Z') c = 'A';
                }
                new_str1 += c;
            }
            for(Character c : s2.toCharArray()) {
                long tmp1 = sum2;
                while(tmp1-- > 0) {
                    c++;
                    if (c > 'Z') c = 'A';
                }
                new_str2 += c;
            }
            // Merge
            String new_str3 = "";

            for(int i = 0; i < new_str1.length(); i++) {
                int res = mp.get(new_str2.charAt(i));
                Character c = new_str1.charAt(i);
                while(res-- > 0) {
                    c++;
                    if (c > 'Z') c = 'A';
                } 
                new_str3 += c;
            }
            System.out.println(new_str3);
            // System.out.println(new_str1 + " " + new_str2);
            // System.out.println(tmp);
            // System.out.println(s1 + " " + s2);
        }
        sc.close();
    }
}