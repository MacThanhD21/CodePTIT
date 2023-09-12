package OOP;



import java.util.ArrayList;
import java.util.Scanner;

class nhanVien {
    private String maNV, hoTen, gioiTinh, ngaySinh, diaChi, maSoThue, hopDong;

    public nhanVien(String maNV, String hoTen, String gioiTinh, String ngaySinh, String diaChi, String maSoThue, String hopDong) {
        this.maNV = maNV;
        this.hoTen = hoTen;
        this.gioiTinh = gioiTinh;
        this.ngaySinh = ngaySinh;
        this.diaChi = diaChi;
        this.maSoThue = maSoThue;
        this.hopDong = hopDong;
    }

    public nhanVien() {
    }

    public String toString(){
        return this.maNV+" "+this.hoTen+" "+this.gioiTinh+" "+this.ngaySinh+" "+this.diaChi+" "+this.maSoThue+" "+this.hopDong;
    }
}


public class J05006 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<nhanVien> nv = new ArrayList<>();
        int n = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            nv.add(new nhanVien(String.format("%05d", i + 1), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        for (nhanVien x : nv) {
            System.out.println(x);
        }
    }
}