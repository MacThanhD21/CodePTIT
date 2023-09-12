package OOP;

import java.util.ArrayList;
import java.util.Scanner;

public class J05036 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<matHang> mh = new ArrayList<>();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            mh.add(new matHang("MH" + String.format("%02d", i + 1), sc.nextLine(), sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }
        for (matHang x : mh) {
            System.out.println(x);
        }
    }
}


class matHang {
    private String maMH, tenMH, donVi;
    private int giaNhap, soLuong;

    public matHang() {
    }

    public matHang(String maMH, String tenMH, String donVi, int giaNhap, int soLuong) {
        this.maMH = maMH;
        this.tenMH = tenMH;
        this.donVi = donVi;
        this.giaNhap = giaNhap;
        this.soLuong = soLuong;
    }

    public int phiVanChuyen() {
        return (int) Math.round((this.giaNhap * this.soLuong) * 0.05);
    }

    public int thanhTien() {
        return this.giaNhap * soLuong + phiVanChuyen();
    }

    public int giaBan() {
        return (int) Math.round(thanhTien() + 0.02 * thanhTien());
    }

    public String toString() {
        return this.maMH + " " + this.tenMH + " " + this.donVi + " " + this.phiVanChuyen() + " " + this.thanhTien() + " " + this.giaBan();
    }
}

