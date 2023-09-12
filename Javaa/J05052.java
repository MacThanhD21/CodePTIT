
import java.util.*;

class Bill {
    private String name, type, id;
    private int dgia, Soluong;

    public Bill(String name, String type, String id, int dgia, int Soluong) {
        this.name = name;
        this.type = type;
        this.id = id;
        this.dgia = dgia;
        this.Soluong = Soluong;
    }

    public String getType() {
        return this.id.substring(4);
    }

    public String getOrderNumber() {
        return this.id.substring(1, 4);
    }

    public int getDiscount() {
        if (this.getType().equals("1")) {
            return (int) (0.5 * this.dgia * this.Soluong);
        } else {
            return (int) (0.3 * this.dgia * this.Soluong);
        }
    }

    public int getTotalMon() {
        return this.Soluong * this.dgia - this.getDiscount();
    }

    @Override
    public String toString() {
        return this.name + " " + this.type + " " + this.id + " " + this.getOrderNumber() + " " + this.getDiscount()
                + " " + this.getTotalMon();
    }
}

public class J05052 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<Bill> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String[] s = sc.nextLine().split("\\s+");
            arr.add(new Bill(s[0], s[1], sc.nextLine(), Integer.parseInt(sc.nextLine()),
                    Integer.parseInt(sc.nextLine())));
        }
        for (Bill x : arr) {
            System.out.println(x);
        }
    }
}