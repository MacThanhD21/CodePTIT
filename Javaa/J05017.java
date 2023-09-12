

import java.util.*;
import java.io.*;

class Bill {
    private String id, name;
    private int o_idx, n_idx;


    public Bill(int id, String name, int o_idx, int n_idx) {
        this.id = "KH" + String.format("%02d", id);
        this.name = name;
        this.o_idx = o_idx;
        this.n_idx = n_idx;
    }

    public long getTotalMoneyaddFee() {
        long res = 0;
        long M3_Num = this.n_idx - this.o_idx;
        if (M3_Num > 50) {
            res = 50 * 100;
            if (M3_Num > 100) {
                res += 50 * 150;
                res += (M3_Num - 100) * 200;
                res = Math.round(res * 1.05);
            } else {
                res += (M3_Num - 50) * 150;
                res = Math.round(res * 1.03);
            }
        } else {
            res = M3_Num * 102;
        }
        return res;
    }


    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.getTotalMoneyaddFee();
    }
}

class SortByTotalMoney implements Comparator<Bill> {

    @Override
    public int compare(Bill o1, Bill o2) {
        return (int)(o2.getTotalMoneyaddFee() - o1.getTotalMoneyaddFee());
    }
}
public class J05017 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        ArrayList<Bill> arr = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            arr.add(new Bill(i + 1, sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        }
        
        Collections.sort(arr, new SortByTotalMoney());

        for(Bill x : arr) {
            System.out.println(x);
        }
        sc.close();
    }
}
