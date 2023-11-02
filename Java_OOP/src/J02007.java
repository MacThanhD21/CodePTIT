import java.util.*;

public class J02007 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        int test = 1;
        while(t-- > 0) {
            System.out.println("Test " + test++ + ":");
            int n = sc.nextInt();
            LinkedHashMap<Integer, Integer> mp = new LinkedHashMap<>();

            for(int i = 0; i < n; i++){
                Integer a = sc.nextInt();
                if(mp.containsKey(a)) {
                    int fre = mp.get(a);
                    mp.put(a, fre + 1);
                }
                else{
                    mp.put(a, 1);
                }
            }

            Set<Map.Entry<Integer, Integer>> entrySet = mp.entrySet();

            for(Map.Entry<Integer, Integer> entry : entrySet) {
                System.out.println(entry.getKey() + " xuat hien " + entry.getValue() + " lan");
            }
        }
    }    
}