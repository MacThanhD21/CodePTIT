package OOP;


import java.util.ArrayList;
import java.util.Scanner;


class SinhVien {
    private String maSV, hoTen, lop, DOB;
    private double gpa;

    public SinhVien() {
    }

    public SinhVien(String maSV, String hoTen, String lop, String DOB, double gpa) {
        this.maSV = maSV;
        this.hoTen = hoTen;
        this.lop = lop;
        this.DOB = DOB;
        this.gpa = gpa;
    }

    public void chuanHoa() {
        StringBuilder sb = new StringBuilder(this.DOB);
        if (sb.charAt(1) == '/') {
            sb.insert(0, "0");
        }
        if (sb.charAt(4) == '/') {
            sb.insert(3, "0");
        }
        this.DOB = sb.toString();
    }

    public String toString() {
        chuanHoa();
        return this.maSV + " " + this.hoTen + " " + this.lop + " " + this.DOB + " " + String.format("%.2f", this.gpa);
    }
}


public class J05003 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<SinhVien> sv = new ArrayList<>();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            SinhVien x = new SinhVien("B20DCCN" + String.format("%03d", i + 1), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextDouble());
            sv.add(x);
        }
        for (SinhVien x : sv) {
            System.out.println(x);
        }
        sc.close();
    }
}

