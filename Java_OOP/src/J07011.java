import java.io.*;
import java.util.*;

public class J07011 {
    public static void main(String[] args) throws FileNotFoundException{
        
        // Scanner sc = new Scanner(System.in);
        Scanner sc = new Scanner(new File("VANBAN.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<String> arr = new ArrayList<String>();
        while(n-- > 0){
            arr.add(sc.nextLine().toLowerCase());
        }
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        
        for (String i : arr) {
            String[] tmp = i.split("\\W\\s*");
            for (String j : tmp) {
                // Case: whiteSpace
                if (!j.equals("")) {
                    map.put(j, map.getOrDefault(j, 0) + 1);
                }
            }
        }

        List<Map.Entry<String, Integer>> entries = new ArrayList<>(map.entrySet());
        Collections.sort(entries, (o1, o2) -> o1.getKey().compareTo(o2.getKey()));
        Collections.sort(entries, (o1, o2) -> o2.getValue().compareTo(o1.getValue()));

        entries.forEach(i -> System.out.println(i.getKey() + " " + i.getValue()));
    }
}