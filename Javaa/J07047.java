import java.io.File;
import java.io.FileNotFoundException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

class Hotel {
    private String sign, name_Room;
    private int single_Price;
    private double Fee;

    public Hotel(String sign, String name_Room, int single_Price, double Fee) {
        this.sign = sign;
        this.name_Room = name_Room;
        this.single_Price = single_Price;
        this.Fee = Fee;
    }
    public String getSign() {
        return this.sign;
    }

    public String getName_Room() {
        return this.name_Room;
    }

    public int getSingle_Price() {
        return this.single_Price;
    }

    public double getFee() {
        return this.Fee;
    }
}

class Client implements Comparable<Client>{
    private String id, name, room_code, in_date, out_date;
    public int single_Price;
    public double Fee;

    public Client(int id, String name, String room_code, String in_date, String out_date, ArrayList<Hotel> dsHotel) {
        this.id = "KH" + String.format("%02d", id);
        this.name = name;
        this.room_code = room_code;
        this.in_date = in_date;
        this.out_date = out_date;

        for(Hotel tmp : dsHotel) {
            if(tmp.getSign().equals(this.room_code.substring(2, 3))) {
                this.single_Price = tmp.getSingle_Price();
                this.Fee = tmp.getFee();
                break;
            }
        }
    }

    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public String getRoom_code() {
        return this.room_code;
    }

    public String getIn_date() {
        return this.in_date;
    }

    public String getOut_date() {
        return this.out_date;
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
    public double getTotalMoney() {
        
        int date = this.getDateNum();
        if(date < 1) {
            date = 1;
        }
        double totalFee = date * this.single_Price;
        double fee = totalFee * this.Fee;
        
        if(date < 1) {
            totalFee = this.single_Price;
            return (totalFee + fee);
        }
        if(date < 10) {
            return (totalFee + fee);
        }
        else if(date < 20) {
            return (totalFee + fee) * (1 - 0.02);
        }
        else if(date < 30) {
            return (totalFee + fee) * (1 - 0.04);
        }
        else{
            return (totalFee + fee) * (1 - 0.06);
        }
    }
    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.room_code  + " " + this.getDateNum() + " " + String.format("%.2f", this.getTotalMoney());
    }

    @Override
    public int compareTo(Client o) {
        // TODO Auto-generated method stub
        return o.getDateNum() - this.getDateNum();
    }
}

public class J07047 {
    public static void main(String[] args) throws FileNotFoundException{
        // Scanner sc = new Scanner(new File("DATA.in"));
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        ArrayList <Hotel> dsHotel = new ArrayList<>();
        while(n-- > 0) {
            String s = sc.nextLine();
            String[] tmp = s.split("\\s+");
            dsHotel.add(new Hotel(tmp[0], tmp[1], Integer.parseInt(tmp[2]), Double.parseDouble(tmp[3])));
        }
        n = Integer.parseInt(sc.nextLine());
        ArrayList <Client> arr2 = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            arr2.add(new Client(i + 1, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), dsHotel));
        }
        Collections.sort(arr2);
        for(Client tmp : arr2) {
            System.out.println(tmp);
        }
    }
}
