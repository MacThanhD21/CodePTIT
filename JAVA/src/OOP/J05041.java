package OOP;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05041 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<nhanVien> nv = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            nv.add(new nhanVien("NV" + String.format("%02d", i + 1), sc.nextLine(), sc.nextInt(), sc.nextInt(), sc.next()));
        }
        Collections.sort(nv, new Comparator<nhanVien>() {
            @Override
            public int compare(nhanVien o1, nhanVien o2) {
                return o2.tong() - o1.tong();
            }
        });
        for (nhanVien x : nv) {
            System.out.println(x);
        }
    }
}

class nhanVien {
    private String maNV, hoTen, chucVu;
    private int luong, soNgay;

    public nhanVien() {
    }

    public nhanVien(String maNV, String hoTen, int luong, int soNgay, String chucVu) {
        this.maNV = maNV;
        this.hoTen = hoTen;
        this.luong = luong;
        this.soNgay = soNgay;
        this.chucVu = chucVu;
    }

    public int luongThang() {
        return this.luong * soNgay;
    }

    public int thuong() {
        if (this.soNgay >= 25) {
            return (int) (luongThang() * 0.2);
        } else if (this.soNgay >= 22) {
            return (int) (luongThang() * 0.1);
        } else {
            return 0;
        }
    }

    public int phuCap() {
        if (this.chucVu.compareTo("GD") == 0) {
            return 250000;
        } else if (this.chucVu.compareTo("PGD") == 0) {
            return 200000;
        } else if (this.chucVu.compareTo("TP") == 0) {
            return 180000;
        } else {
            return 150000;
        }
    }

    public int tong() {
        return luongThang() + thuong() + phuCap();
    }

    public String toString() {
        return this.maNV + " " + this.hoTen + " " + luongThang() + " " + thuong() + " " + phuCap() + " " + tong();
    }
}

