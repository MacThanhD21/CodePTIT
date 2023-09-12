package OOP;

import java.util.Scanner;

 class phanSo {
    private long a, b;

    public phanSo() {
    }

    public phanSo(long a, long b) {
        this.a = a;
        this.b = b;
    }

    long gcd(long a, long b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    phanSo add(phanSo x) {
        phanSo res = new phanSo();
        res.b = this.b * x.b;
        res.a = this.a * x.b + x.a * this.b;
        return res;
    }

    void rutGon() {
        long ucln = gcd(this.a, this.b);
        this.a /= ucln;
        this.b /= ucln;
    }

    @Override
    public String toString() {
        rutGon();
        return this.a + "/" + this.b;
    }
}


public class J04004 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        phanSo ps1 = new phanSo(sc.nextLong(), sc.nextLong());
        phanSo ps2 = new phanSo(sc.nextLong(), sc.nextLong());
        System.out.println(ps1.add(ps2));
    }
}