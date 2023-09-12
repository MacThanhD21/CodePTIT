package OOP;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;

class bangDiem {
    private String id, tenHS;
    private double Toan, tiengViet, ngoaiNgu, vatLy, hoaHoc, sinhHoc, lichSu, Dia, GDCD, congNghe;

    public bangDiem() {
    }

    public bangDiem(String id, String tenHS, double toan, double tiengViet, double ngoaiNgu, double vatLy, double hoaHoc, double sinhHoc, double lichSu, double dia, double GDCD, double congNghe) {
        this.id = id;
        this.tenHS = tenHS;
        Toan = toan;
        this.tiengViet = tiengViet;
        this.ngoaiNgu = ngoaiNgu;
        this.vatLy = vatLy;
        this.hoaHoc = hoaHoc;
        this.sinhHoc = sinhHoc;
        this.lichSu = lichSu;
        Dia = dia;
        this.GDCD = GDCD;
        this.congNghe = congNghe;
    }

    public String getId() {
        return id;
    }

    public double diemTB() {
        return (this.Toan * 2 + this.tiengViet * 2 + this.ngoaiNgu + this.vatLy + this.hoaHoc + this.sinhHoc + this.lichSu + this.Dia + this.GDCD + this.congNghe) / 12.0;
    }

    public String toString() {
        String res;
        double tb = (double) Math.round(diemTB() * 10) / 10;
        if (tb >= 9.0) {
            res = "XUAT SAC";
        } else if (tb >= 8.0) {
            res = "GIOI";
        } else if (tb >= 7.0) {
            res = "KHA";
        } else if (tb >= 5.0) {
            res = "TB";
        } else res = "YEU";
        return this.id + " " + this.tenHS + " " + String.format("%.1f", tb) + " " + res;
    }
}

class SortBD implements Comparator<bangDiem> {
    public int compare(bangDiem bd1, bangDiem bd2) {
        if (bd1.diemTB() != bd2.diemTB()) {
            if (bd1.diemTB() < bd2.diemTB()) return 1;
            else return -1;
        } else {
            return bd1.getId().compareTo(bd2.getId());
        }
    }
}



public class J05018 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        ArrayList<bangDiem> bd = new ArrayList<>();
        for (int i = 0; i < t; i++) {
            sc.nextLine();
            bd.add(new bangDiem("HS" + String.format("%02d", i + 1), sc.nextLine(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble(),
                    sc.nextDouble(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble()));
        }
        Collections.sort(bd, new SortBD());
        for (bangDiem x : bd) {
            System.out.println(x);
        }
    }
}



