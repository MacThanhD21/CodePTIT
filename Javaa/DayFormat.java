import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class DayFormat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String inputDateString = sc.nextLine();
        DateTimeFormatter outputFormatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

        LocalDate date = LocalDate.parse(inputDateString);
        System.out.println(date.toString());
        String formattedDate = date.format(outputFormatter);

        System.out.println("Formatted Date: " + formattedDate);
    }
}
