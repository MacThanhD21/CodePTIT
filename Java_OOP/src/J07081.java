import java.io.*;
import java.math.BigInteger;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;

class SV implements Comparable<SV> {
    private String id, ten, dt, email;

    public SV(String id, String ten, String dt, String email) {
        this.id = id;
        this.ten = ten;
        this.dt = dt;
        this.email = email;
    }

    public String getTen() {
        String[] arr = ten.split("\\s+");
        return arr[arr.length - 1];
    }

    @Override
    public int compareTo(SV o) {
        if (this.getTen().equals(o.getTen())) {
            if (this.ten.compareTo(o.ten) == 0) {
                return this.id.compareTo(o.id);
            } else {
                return this.ten.compareTo(o.ten);
            }
        } else {
            return this.getTen().compareTo(o.getTen());
        }
    }

    @Override
    public String toString() {
        return id + " " + ten + " " + dt + " " + email;
    }
}

public class J07081 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<SV> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(new SV(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(arr);
        for (SV x : arr) {
            System.out.println(x);
        }
    }
}