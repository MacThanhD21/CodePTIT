
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        // String s = "tuan anh";
        // System.out.println(s.chars());

        // Convert the IntStream to a string of characters and print it
        // s.chars().forEach(c -> System.out.print((char) c));
        
        TreeMap<Character, Integer> mp = new TreeMap<>();
        
        for(int i = 0; i < 26; i++) {
            System.out.println((char)(i + 65)+ " " + i);
            mp.put((char)(i + 65), i);
        }

        Set<Map.Entry<Character, Integer>> entrySet = mp.entrySet();

        for(Map.Entry<Character, Integer> entry : entrySet) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }

        String s = "Hoang Tien Hung";
        for(Character c : s.toCharArray()) {
            System.out.print(c + " ");
        }
    }
}
