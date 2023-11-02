
import java.util.*;

class Electric_Bill implements Comparable<Electric_Bill> {
    private String id, SD_type;
    private int old_idx, new_idx;

    public Electric_Bill(int id, String SD_type, int old_idx, int new_idx) {
        this.id = "KH" + String.format("%02d", id);
        this.SD_type = SD_type;
        this.old_idx = old_idx;
        this.new_idx = new_idx;
    }

    public int getCoefficient() {
        if (this.SD_type.equals("KD"))
            return 3;
        else if (this.SD_type.equals("NN"))
            return 5;
        else if (this.SD_type.equals("TT"))
            return 4;
        else {
            return 2;
        }
    }

    public int getMoney() {
        return this.getCoefficient() * (new_idx - old_idx) * 550;
    }

    public double getAdditional() {
        int res = new_idx - old_idx;
        if (res < 50) {
            return 0;
        } else if (res <= 100) {
            return Math.round(this.getMoney() * 0.35);
        } else {
            return Math.round(this.getMoney());
        }
    }

    public double getTotalMoney() {
        return this.getAdditional() + this.getMoney();
    }

    @Override
    public int compareTo(Electric_Bill o) {
        if (o.getTotalMoney() < this.getTotalMoney())
            return -1;
        else
            return 1;
    }

    @Override
    public String toString() {
        return this.id + " " + this.getCoefficient() + " " + this.getMoney() + " "
                + String.format("%.0f", this.getAdditional()) + " "
                + String.format("%.0f", this.getTotalMoney());
    }
}

public class J05051 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        ArrayList<Electric_Bill> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            arr.add(new Electric_Bill((i + 1), sc.nextLine(), Integer.parseInt(sc.nextLine()),
                    Integer.parseInt(sc.nextLine())));
        }

        Collections.sort(arr);

        for (Electric_Bill x : arr) {
            System.out.println(x);
        }
    }
}
