import java.io.*;
import java.util.*;

public class J07012 {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException{
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("DATA.in"));

        ArrayList <String> arr = (ArrayList<String>) ois.readObject();

        HashMap<String, Integer> map = new HashMap<String, Integer>();
        
        for (String i : arr) {
            // Xâu sẽ ngắt bởi quy luật :
            // Gặp 1 ký tự không phải là ký tự chữ số và THEO SAU Nó là không có hoặc có nhiều hơn 1 ký tự khoảng trắng
            // *: {0,many}
            // +: {1,many}
            String[] tmp = i.toLowerCase().split("\\W\\s*");
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