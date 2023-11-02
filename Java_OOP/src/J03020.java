

import java.util.*;

public class J03020 {

    public static boolean check(String s) {
        StringBuilder sb = new StringBuilder(s);
        String tmp = sb.reverse().toString();
        return tmp.equals(s);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int max_Size = 0;
        
        LinkedHashMap<String, Integer> mp = new LinkedHashMap<>();

        while (sc.hasNext()) {
            String s = sc.next();
            if(check(s) && max_Size <= s.length()) {
                max_Size = s.length();
                if(mp.containsKey(s)) {
                    int fre = mp.get(s);
                    fre++;
                    mp.put(s, fre);
                } else {
                    mp.put(s, 1);
                }
            }
        }
        // System.out.println(max_Size);
        Set<Map.Entry<String, Integer>> entrySet = mp.entrySet();

        for (Map.Entry<String, Integer> entry : entrySet) {
            if(entry.getKey().length() == max_Size) {
                System.out.println(entry.getKey() + " " + entry.getValue());
            }
        }

        sc.close();
    }
}
