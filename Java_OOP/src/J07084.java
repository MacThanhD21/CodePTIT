import java.util.*;
import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

class Online_Time {
    private String name, st_Time, en_Time;
    private String in_date, out_date;
    private String in_Hour, out_Hour;

    public Online_Time(String name, String in_date, String out_date, String in_Hour, String out_Hour) {
        this.name = name;
        this.in_date = in_date;
        this.out_date = out_date;
        this.in_Hour = in_Hour;
        this.out_Hour = out_Hour;
    }
    
    public int getDateNum() {
        String date1Str = this.in_date;
        String date2Str = this.out_date;
        
        // Define the date format pattern
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        
        // Parse the date strings into LocalDate objects using the specified pattern
        LocalDate date1 = LocalDate.parse(date1Str, formatter);
        LocalDate date2 = LocalDate.parse(date2Str, formatter);

        // Calculate the number of days between the two dates
        long daysBetween = ChronoUnit.DAYS.between(date1, date2);

        return (int) daysBetween;
    }
    public int getOnlineTime() {
        int dateNum = this.getDateNum();
        return 0;
    }

    @Override
    public String toString() {
        return this.name + " " + this.getOnlineTime();
    }
}
public class J07084 {
    public static void main(String[] args) throws FileNotFoundException{
        Scanner sc = new Scanner(System.in);

        // Scanner sc = new Scanner(new File("ONLINE.in"));

        int n = Integer.parseInt(sc.nextLine());

        ArrayList <Online_Time> arr = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            arr.add(new Online_Time(sc.nextLine(), sc.next(), sc.nextLine().substring(1), sc.next(), sc.nextLine().substring(1)));
        }
        for(Online_Time x : arr) {
            System.out.println(x);
        }
    }
}
