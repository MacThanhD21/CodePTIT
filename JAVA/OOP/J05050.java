package OOP;


import java.util.ArrayList;
import java.util.Scanner;

public class J05050 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<khachHang> kh = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            kh.add(new khachHang("KH" + String.format("%02d", i + 1), sc.nextLine(), sc.nextDouble(), sc.nextDouble()));
        }
        for (khachHang x : kh) {
            System.out.println(x);
        }
    }
}

class khachHang {
    private String maKH, loaiSD;
    private double soCu, soMoi;

    public khachHang() {
    }

    public khachHang(String maKH, String loaiSD, double soCu, double soMoi) {
        this.maKH = maKH;
        this.loaiSD = loaiSD;
        this.soCu = soCu;
        this.soMoi = soMoi;
    }

    public double heSo() {
        if (this.loaiSD.contentEquals("KD"))
            return 3;
        else if (this.loaiSD.contentEquals("NN"))
            return 5;
        else if (this.loaiSD.contentEquals("TT"))
            return 4;
        else return 2;
    }

    public double thanhTien() {
        return (this.soMoi - this.soCu) * heSo() * 550;
    }

    public double phuTroi() {
        double x = this.soMoi - this.soCu;
        if (x > 100)
            return thanhTien() * 100.0 / 100.0;
        else if (x >= 50)
            return thanhTien() * 35.0 / 100.0;
        else return 0;
    }

    public double tongTien() {
        return phuTroi() + thanhTien();
    }

    public String toString() {
        return this.maKH + " " + String.format("%.0f", heSo()) + " " + String.format("%.0f", thanhTien()) + " " + String.format("%.0f", phuTroi()) + " " + String.format("%.0f", tongTien());
    }
}

