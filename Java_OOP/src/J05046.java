package OOP;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class matHang {
    private String maMH, tenMH;
    private int soLuong, donGia;

    public matHang(String maMH, String tenMH, int soLuong, int donGia) {
        this.maMH = maMH;
        this.tenMH = tenMH;
        this.soLuong = soLuong;
        this.donGia = donGia;
    }

    public double phanTram() {
        if (this.soLuong > 10)
            return 0.05;
        else if (this.soLuong >= 8)
            return 0.02;
        else if (this.soLuong >= 5)
            return 0.01;
        else
            return 0.00;
    }

    public int chietKhau() {
        return (int) (this.donGia * this.soLuong * phanTram());
    }

    public String toString() {
        return this.maMH + " " + this.tenMH + " " + chietKhau() + " " + (this.donGia * this.soLuong - chietKhau());
    }
}

public class J05046 {
    public static String getId(String s) {
        String res = "";
        String[] a = s.split("\\s+");
        for (int i = 0; i < a.length - 1; i++) {
            res += Character.toUpperCase(a[i].charAt(0));
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<matHang> mh = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            String s = sc.nextLine();
            int so;
            String tmp = getId(s);
            if (map.containsKey(tmp)) {
                so = map.get(tmp) + 1;
            } else {
                so = 1;
            }
            map.put(tmp, so);
            mh.add(new matHang(tmp + String.format("%02d", so), s, sc.nextInt(), sc.nextInt()));
        }
        for (matHang x : mh) {
            System.out.println(x);
        }
    }
}
