
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        // // String s = "tuan anh";
        // // System.out.println(s.chars());

        // // Convert the IntStream to a string of characters and print it
        // // s.chars().forEach(c -> System.out.print((char) c));

        // TreeMap<Character, Integer> mp = new TreeMap<>();

        // for(int i = 0; i < 26; i++) {
        // System.out.println((char)(i + 65)+ " " + i);
        // mp.put((char)(i + 65), i);
        // }

        // Set<Map.Entry<Character, Integer>> entrySet = mp.entrySet();

        // for(Map.Entry<Character, Integer> entry : entrySet) {
        // System.out.println(entry.getKey() + " " + entry.getValue());
        // }

        // String s = "Hoang Tien Hung";
        // for(Character c : s.toCharArray()) {
        // System.out.print(c + " ");
        // }

        // Define your two dates as strings in the format "yyyy-MM-dd"
        // String date1Str = "2010-08-03";
        // String date2Str = "2010-08-01";

        // // Parse the date strings into LocalDate objects
        // LocalDate date1 = LocalDate.parse(date1Str);
        // LocalDate date2 = LocalDate.parse(date2Str);

        // // Calculate the number of days between the two dates
        // long daysBetween = ChronoUnit.DAYS.between(date2, date1);

        // System.out.println("Number of days between " + date2Str + " and " + date1Str + " is " + daysBetween + " days.");

        String s = "B21DCCN677 Hello 8.5";
        String[] tmp = s.split("\\s+");
        // for(String x : tmp) {
        //     System.out.println(x);
        // }
        System.out.println(tmp[0]);
        System.out.println(tmp[1]);
        System.out.println(tmp[2]);
        // System.out.println(s);
    }
}
