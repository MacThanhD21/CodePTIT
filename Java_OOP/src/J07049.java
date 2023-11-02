
import java.util.*;
import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

class Productt {
    private String id_Pro, name_Pro;
    private long price_Pro, warrantly_period_Pro;


    public Productt(String id_Pro, String name_Pro, long price_Pro, long warrantly_period_Pro) {
        this.id_Pro = id_Pro;
        this.name_Pro = name_Pro;
        this.price_Pro = price_Pro;
        this.warrantly_period_Pro = warrantly_period_Pro;
    }

    public String getId_Pro() {
        return this.id_Pro;
    }
    public String getName_Pro() {
        return this.name_Pro;
    }

    public long getPrice_Pro() {
        return this.price_Pro;
    }

    public long getWarrantly_period_Pro() {
        return this.warrantly_period_Pro;
    }
}

class Customerr implements Comparable<Customerr> {
    private String id_Cus, name_Cus, add_Cus, id_Pro; private long quantity;
    private LocalDate ngayMua, ExpirationDate;

    public long price = 0, warrantly_period_Pro = 0;

    public Customerr(int id_Cus, String name_Cus, String add_Cus, String id_Pro, long quantity, String pur_Date, ArrayList<Productt> products) {
        this.id_Cus = "KH" + String.format("%02d", id_Cus);
        this.name_Cus = name_Cus;
        this.add_Cus = add_Cus;
        this.id_Pro = id_Pro;
        this.quantity = quantity;
        this.ngayMua = DateTimeFormatter.ofPattern("dd/MM/yyyy").parse(pur_Date, LocalDate::from) ;

        for(Productt i : products) {
            if(i.getId_Pro().equals(id_Pro)) {
                this.price = i.getPrice_Pro();
                this.warrantly_period_Pro = i.getWarrantly_period_Pro();
            }
        }
        this.ExpirationDate = this.ngayMua.plusMonths(this.warrantly_period_Pro);

    }
    public long getTotalMoney() {
        return this.price * this.quantity;
    }
    
    @Override
    public String toString() {
        return this.id_Cus + " " + this.name_Cus + " " + this.add_Cus + " " + this.id_Pro + " " + this.getTotalMoney() + " " + DateTimeFormatter.ofPattern("dd/MM/yyyy").format(this.ExpirationDate);
    }
    @Override
    public int compareTo(Customerr o) {
        // TODO Auto-generated method stub
        if(this.ExpirationDate.compareTo(o.ExpirationDate) > 0) return 1;
        else if(this.ExpirationDate.compareTo(o.ExpirationDate) < 0) return -1;
        else return this.id_Cus.compareTo(o.id_Cus);
    }
}

public class J07049 {
    public static void main(String[] args) throws FileNotFoundException, Exception{
        Scanner sc = new Scanner(System.in);
        // Scanner sc = new Scanner(new File("MUAHANG.in"));
        int n = Integer.parseInt(sc.nextLine());

        ArrayList <Productt> arr1 = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            String id_Pro = sc.nextLine();
            String name_Pro = sc.nextLine();
            long price_Pro = Long.parseLong(sc.nextLine());
            long warrantly_period_Pro = Long.parseLong(sc.nextLine());
            arr1.add(new Productt(id_Pro, name_Pro, price_Pro, warrantly_period_Pro));
        }

        ArrayList <Customerr> arr2 = new ArrayList<>();
        int m = Integer.parseInt(sc.nextLine());
        for(int i = 0; i < m; i++) {
            String name_Cus = sc.nextLine();
            String add_Cus = sc.nextLine();
            String id_Pro = sc.nextLine();
            long quantity = Long.parseLong(sc.nextLine());
            String pur_Date = sc.nextLine();
            arr2.add(new Customerr(i + 1, name_Cus, add_Cus, id_Pro, quantity, pur_Date, arr1));
        }
        Collections.sort(arr2);
        for(Customerr x : arr2) {
            System.out.println(x);
        }
    }
}
