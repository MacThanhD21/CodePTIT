package OOP;


import java.util.ArrayList;
import java.util.Scanner;

public class J05009 {
    private static int n;
    private static double res;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<thiSinh> ts = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            ts.add(new thiSinh(String.format("%1d", i + 1), sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble()));
        }
        double res = 0.0;
        for (thiSinh x : ts) {
            res = Math.max(res, x.tongDiem());
        }
        for (thiSinh x : ts) {
            if (x.tongDiem() == res) {
                System.out.println(x);
            }
        }
    }
}

class thiSinh {
    private String maTS, hoTen, ngaySinh;
    private double diem1, diem2, diem3;

    public thiSinh() {
    }

    public thiSinh(String maTS, String hoTen, String ngaySinh, double diem1, double diem2, double diem3) {
        this.maTS = maTS;
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.diem1 = diem1;
        this.diem2 = diem2;
        this.diem3 = diem3;
    }

    public double tongDiem() {
        return this.diem1 + this.diem2 + this.diem3;
    }

    public String toString() {
        return this.maTS + " " + this.hoTen + " " + this.ngaySinh + " " + String.format("%.1f", tongDiem());
    }
}

