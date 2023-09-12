package OOP;

import java.util.ArrayList;
import java.util.Scanner;

class giangVien {
    private String maGV, hoTen, boMon;

    public giangVien() {
    }

    public giangVien(String maGV, String hoTen, String boMon) {
        this.maGV = maGV;
        this.hoTen = hoTen;
        this.boMon = boMon;
    }

    public String getMaGV() {
        return maGV;
    }

    public String getHoTen() {
        return this.hoTen.toUpperCase();
    }

    public String mon() {
        String res = this.boMon.toUpperCase();
        String[] a = res.split("\\s+");
        String tmp = "";
        for (String x : a) {
            tmp += x.charAt(0);
        }
        return tmp;
    }

    public String toString() {
        return this.maGV + " " + this.hoTen + " " + mon();
    }
}



public class J05027 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<giangVien> gv = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            gv.add(new giangVien("GV" + String.format("%02d", i), sc.nextLine(), sc.nextLine()));
        }
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String s = sc.nextLine();
            System.out.println("DANH SACH GIANG VIEN THEO TU KHOA " + s + ":");
            for (giangVien x : gv) {
                if (x.getHoTen().contains(s.toUpperCase())) {
                    System.out.println(x);
                }
            }
        }
    }
}


