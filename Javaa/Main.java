
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.Calendar;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

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

        // String s = "B21DCCN677 Hello 8.5";
        // String[] tmp = s.split("\\s+");
        // for(String x : tmp) {
        //     System.out.println(x);
        // }
        // System.out.println(tmp[0]);
        // System.out.println(tmp[1]);
        // System.out.println(tmp[2]);
        // System.out.println(s);
        // int numberOfMonths = 10; // Number of months to add
        // String purchaseDateStr = "11/01/2022"; // Purchase date in MM/dd/yyyy format

        // DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
        // try {
        //     Date purchaseDate = dateFormat.parse(purchaseDateStr);

        //     // Create a calendar instance and set it to the purchase date
        //     Calendar calendar = Calendar.getInstance();
        //     calendar.setTime(purchaseDate);

        //     // Add the specified number of months
        //     calendar.add(Calendar.MONTH, numberOfMonths);

        //     // Calculate the expiration date
        //     Date expirationDate = calendar.getTime();

        //     // Format and print the expiration date
        //     String expirationDateStr = dateFormat.format(expirationDate);
        //     System.out.println("Expiration Date: " + expirationDateStr);
        // } catch (ParseException e) {
        //     e.printStackTrace();
        // }
        int numberOfMonths = 10; // Số tháng cần thêm
        String purchaseDateStr = "11/01/2022"; // Ngày mua dưới dạng chuỗi MM/dd/yyyy

        DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
        
        try {
            Date purchaseDate = dateFormat.parse(purchaseDateStr);
            purchaseDateStr = dateFormat.format(purchaseDate);
            String[] parts = purchaseDateStr.split("/");
            int purchaseMonth = Integer.parseInt(parts[0]);
            int purchaseDay = Integer.parseInt(parts[1]);
            int purchaseYear = Integer.parseInt(parts[2]);

            int newMonth = purchaseMonth + numberOfMonths;
            int newYear = purchaseYear + newMonth / 12;
            newMonth %= 12;

            if (newMonth == 0) {
                newMonth = 12;
                newYear--;
            }

            String expirationDateStr = String.format("%02d/%02d/%04d", newMonth, purchaseDay, newYear);
            System.out.println("Ngày hết hạn: " + expirationDateStr);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        
    }
}
