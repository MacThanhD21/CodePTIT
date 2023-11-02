
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class J07021 {
    public static void standardized(String s) {
        String[] words = s.split("\\s+");
        String res = "";
        for (String word : words) {
            res += Character.toUpperCase(word.charAt(0)) + word.substring(1).toLowerCase() + " ";
        }
        System.out.println(res.trim());
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("DATA.in"))) {
            while (true) {

                String s = sc.nextLine().trim();
                if (s.equals("END")) {
                    break;
                }
                standardized(s);
            }
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}