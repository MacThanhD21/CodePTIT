import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;

class GiangVien {
    private String maGV, hoTen, boMon;

    public GiangVien() {
    }

    public GiangVien(String maGV, String hoTen, String boMon) {
        this.maGV = maGV;
        this.hoTen = hoTen;
        this.boMon = boMon;
    }

    public String getMaGV() {
        return maGV;
    }

    public String getTen() {
        String res = this.hoTen.toLowerCase();
        String[] a = res.split("\\s+");
        return a[a.length - 1];
    }

    public String mon() {
        String res = this.boMon.toUpperCase();
        String[] a = res.split("\\s+");
        String tmp = "";
        for (String x : a) {
            tmp += x.charAt(0);
        }
        return tmp;
    }

    public String toString() {
        return this.maGV + " " + this.hoTen + " " + this.mon();
    }
}

class SortGV implements Comparator<GiangVien> {
    public int compare(GiangVien a, GiangVien b) {
        if (a.getTen().compareTo(b.getTen()) != 0) {
            return a.getTen().compareTo(b.getTen());
        } else {
            return a.getMaGV().compareTo(b.getMaGV());
        }
    }
}

public class J05025 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<GiangVien> gv = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            gv.add(new GiangVien("GV" + String.format("%02d", i), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(gv, new SortGV());
        for (GiangVien x : gv) {
            System.out.println(x);
        }
        sc.close();
    }
}



