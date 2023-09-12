package OOP;


import java.util.ArrayList;
import java.util.Scanner;

public class J05048 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<matHang> mh = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            mh.add(new matHang(sc.nextLine(), sc.nextLong()));
        }
        for (matHang x : mh) {
            System.out.println(x);
        }
    }
}

class matHang {
    private String maHang;
    private long nhap;

    public matHang() {
    }

    public matHang(String maHang, long nhap) {
        this.maHang = maHang;
        this.nhap = nhap;
    }

    public double xuat() {
        if (this.maHang.charAt(0) == 'A') {
            return Math.round(60.0/100.0 * this.nhap);
        } else {
            return Math.round(70.0/100.0 * this.nhap);
        }
    }

    public double donGia() {
        if (this.maHang.charAt(this.maHang.length() - 1) == 'Y') {
            return 110000;
        } else {
            return 135000;
        }
    }

    public double tien() {
        return xuat() * donGia();
    }

    public double thue() {
        char dau = this.maHang.charAt(0);
        char cuoi = this.maHang.charAt(this.maHang.length() - 1);
        if (dau == 'A' && cuoi == 'Y') return Math.round(8.0/100.0 * tien());
        else if (dau == 'A' && cuoi == 'N') return Math.round(11.0/100.0 * tien());
        else if (dau == 'B' && cuoi == 'Y') return Math.round(17.0/100.0* tien());
        else return Math.round(22.0/100.0 * tien());
    }

    public String toString() {
        return this.maHang + " " + this.nhap + " " + String.format("%.0f", xuat()) + " " + String.format("%.0f", donGia()) + " " + String.format("%.0f", tien()) + " " + String.format("%.0f", thue());
    }
}

