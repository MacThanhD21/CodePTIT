package OOP;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;

public class J05045 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        ArrayList<nhanVien> nv = new ArrayList<>();
        for (int i = 0; i < t; i++) {
            sc.nextLine();
            nv.add(new nhanVien("NV" + String.format("%02d", i + 1), sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble()));
        }
        Collections.sort(nv, new SortNV());
        for (nhanVien x : nv) {
            System.out.println(x);
        }
    }
}

class nhanVien {
    private String maNV, hoTen, chucVu;
    private double luongCB, ngayCong;

    public nhanVien() {
    }

    public nhanVien(String maNV, String hoTen, String chucVu, double luongCB, double ngayCong) {
        this.maNV = maNV;
        this.hoTen = hoTen;
        this.chucVu = chucVu;
        this.luongCB = luongCB;
        this.ngayCong = ngayCong;
    }

    public String getMaNV() {
        return maNV;
    }

    public double phuCap() {
        if (this.chucVu.equals("GD")) {
            return 500;
        } else if (this.chucVu.equals("PGD")) {
            return 400;
        } else if (this.chucVu.equals("TP")) {
            return 300;
        } else if (this.chucVu.equals("KT")) {
            return 250;
        } else {
            return 100;
        }
    }

    public double tamUng() {
        if ((phuCap() + this.luongCB * this.ngayCong) * 2 / 3 < 25000) {
            return Math.round(((phuCap() + this.luongCB * this.ngayCong) * 2 / 3) / 1000) * 1000;
        } else {
            return 25000;
        }
    }

    public double thuNhap() {
        return this.luongCB * this.ngayCong + phuCap();
    }

    public String toString() {
        return this.maNV + " " + this.hoTen + " " + String.format("%.0f", phuCap()) + " " + String.format("%.0f", (this.luongCB * this.ngayCong)) + " " + String.format("%.0f", tamUng()) + " " + String.format("%.0f", this.luongCB * this.ngayCong + phuCap() - tamUng());
    }
}


class SortNV implements Comparator<nhanVien> {
    public int compare(nhanVien a, nhanVien b){
        if(a.thuNhap()!=b.thuNhap()){
            if(a.thuNhap()<b.thuNhap()){
                return 1;
            }else{
                return -1;
            }
        }else{
            return a.getMaNV().compareTo(b.getMaNV());
        }
    }
}

