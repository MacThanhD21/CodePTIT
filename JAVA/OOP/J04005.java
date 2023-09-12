package OOP;

import java.util.Scanner;

 class thiSinh {
    private String hoTen, ngaySinh;
    private double d1, d2, d3;

    public thiSinh(String hoTen, String ngaySinh, double d1, double d2, double d3) {
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.d1 = d1;
        this.d2 = d2;
        this.d3 = d3;
    }

    public double sum() {
        return this.d1 + this.d2 + this.d3;
    }

    @Override
    public String toString() {
        return this.hoTen + " " + this.ngaySinh + " " + String.format("%.1f",this.sum());
    }
}

public class J04005 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(new thiSinh(sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble()));
    }
}