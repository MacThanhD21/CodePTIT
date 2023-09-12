package OOP;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05034 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<sinhVien> sv = new ArrayList<>();
        int n = sc.nextInt();
        sc.nextLine();
        for (int i = 1; i <= n; i++) {
            sv.add(new sinhVien("" + i, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(sv, new Comparator<sinhVien>() {
            @Override
            public int compare(sinhVien o1, sinhVien o2) {
                return o1.getHoTen().compareTo(o2.getHoTen());
            }
        });
        int q = sc.nextInt();
        sc.nextLine();
        while (q-- > 0) {
            String dn = sc.nextLine();
            for (sinhVien x : sv) {
                if (x.getDoanhNghiep().compareTo(dn) == 0)
                    System.out.println(x);
            }
        }
    }
}


class sinhVien {
    private String stt, maSV, hoTen, lop, email, doanhNghiep;

    public sinhVien() {
    }

    public sinhVien(String stt, String maSV, String hoTen, String lop, String email, String doanhNghiep) {
        this.stt = stt;
        this.maSV = maSV;
        this.hoTen = hoTen;
        this.lop = lop;
        this.email = email;
        this.doanhNghiep = doanhNghiep;
    }

    public String getHoTen() {
        return hoTen;
    }

    public String getDoanhNghiep() {
        return doanhNghiep;
    }

    public String toString() {
        return this.stt + " " + this.maSV + " " + this.hoTen + " " + this.lop + " " + this.email + " " + this.doanhNghiep;
    }
}

