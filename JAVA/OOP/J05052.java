package OOP;

import java.util.ArrayList;
import java.util.Scanner;

class donHang {
    private String tenHang, maHang;
    private double donGia, soLuong;

    public donHang() {
    }

    public donHang(String tenHang, String maHang, double donGia, double soLuong) {
        this.tenHang = tenHang;
        this.maHang = maHang;
        this.donGia = donGia;
        this.soLuong = soLuong;
    }

    public double giamGia() {
        String res = this.maHang.substring(this.maHang.length() - 1);
        if (res.contentEquals("1")) {
            return 50.0 / 100.0 * this.donGia * this.soLuong;
        } else {
            return 30.0 / 100.0 * this.donGia * this.soLuong;
        }
    }

    public String stt() {
        return this.maHang.substring(1, 4);
    }

    public double thanhTien() {
        return this.donGia * this.soLuong - giamGia();
    }

    public String toString(){
        return this.tenHang+" "+this.maHang+" "+stt()+" "+String.format("%.0f",giamGia())+" "+String.format("%.0f", thanhTien());
    }
}

public class J05052 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<donHang> dh = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            dh.add(new donHang(sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble()));
        }
        for (donHang x : dh) {
            System.out.println(x);
        }
    }
}

