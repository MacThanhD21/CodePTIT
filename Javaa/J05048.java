import java.util.*;

class Merchandise {
    private String id;
    private int Import_Quantity;

    public Merchandise(String id, int Import_Quantity) {
        this.id = id;
        this.Import_Quantity = Import_Quantity;
    }

    public int getExport_Quantity() {
        if (this.id.substring(0, 1).equals("A")) {
            return (int) (Math.round(0.6 * this.Import_Quantity));
        } else {
            return (int) (Math.round(0.7 * this.Import_Quantity));
        }
    }

    public int getSingle_Price() {
        if (this.id.endsWith("Y")) {
            return 110000;
        } else {
            return 135000;
        }
    }

    public int getMoney() {
        return this.getExport_Quantity() * this.getSingle_Price();
    }

    public int getTax() {
        String s = this.id;

        if (s.startsWith("A") && s.endsWith("Y")) {
            return (int) (0.08 * this.getMoney());
        } else if (s.startsWith("A") && s.endsWith("N")) {
            return (int) (0.11 * this.getMoney());
        } else if (s.startsWith("B") && s.endsWith("Y")) {
            return (int) (0.17 * this.getMoney());
        } else {
            return (int) (0.22 * this.getMoney());
        }
    }

    @Override
    public String toString() {
        return this.id
                + " " + this.Import_Quantity
                + " " + this.getExport_Quantity()
                + " " + this.getSingle_Price()
                + " " + this.getMoney()
                + " " + this.getTax();
    }

}

public class J05048 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        ArrayList<Merchandise> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            arr.add(new Merchandise(sc.nextLine(), Integer.parseInt(sc.nextLine())));
        }

        for (Merchandise x : arr) {
            System.out.println(x);
        }
        sc.close();
    }
}