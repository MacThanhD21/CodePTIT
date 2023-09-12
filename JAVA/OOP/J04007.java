package OOP;

import java.util.Scanner;

 class nhanVien {
    private String mnv, hoTen, gioiTinh, ngaySinh, diaChi, maSoThue, hopDong;

    public nhanVien(String mnv, String hoTen, String gioiTinh, String ngaySinh, String diaChi, String maSoThue, String hopDong) {
        this.mnv = mnv;
        this.hoTen = hoTen;
        this.gioiTinh = gioiTinh;
        this.ngaySinh = ngaySinh;
        this.diaChi = diaChi;
        this.maSoThue = maSoThue;
        this.hopDong = hopDong;
    }

    @Override
    public String toString() {
        return this.mnv + " " + this.hoTen + " " + this.gioiTinh + " " + this.ngaySinh + " " + this.diaChi + " " + this.maSoThue + " " + this.hopDong;
    }
}

public class J04007 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(new nhanVien("00001", sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
    }
}