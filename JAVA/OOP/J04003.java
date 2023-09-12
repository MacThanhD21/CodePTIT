package OOP;

import java.util.Scanner;

class phanSo {
    private long a, b;

    public phanSo(long a, long b) {
        this.a = a;
        this.b = b;
    }

    long gcd(long a, long b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    void rutGon() {
        long x = gcd(this.a, this.b);
        this.a /= x;
        this.b /= x;
    }

    @Override
    public String toString() {
        rutGon();
        return this.a + "/" + this.b;
    }
}

public class J04003 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        phanSo x = new phanSo(sc.nextLong(), sc.nextLong());
        System.out.println(x);
    }
}