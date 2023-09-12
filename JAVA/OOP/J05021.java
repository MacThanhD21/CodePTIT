package OOP;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05021 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<sinhVien> sv = new ArrayList<>();
        while (sc.hasNextLine()) {
            sv.add(new sinhVien(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(sv, new Comparator<sinhVien>() {
            @Override
            public int compare(sinhVien o1, sinhVien o2) {
                return o1.getMaSV().compareTo(o2.getMaSV());
            }
        });
        for (sinhVien x : sv) {
            System.out.println(x);
        }
        sc.close();
    }
}

class sinhVien {
    private String maSV, hoTen, lop, email;

    public sinhVien() {
    }

    public sinhVien(String maSV, String hoTen, String lop, String email) {
        this.maSV = maSV;
        this.hoTen = hoTen;
        this.lop = lop;
        this.email = email;
    }

    public String getMaSV() {
        return maSV;
    }

    public String toString() {
        return this.maSV + " " + this.hoTen + " " + this.lop + " " + this.email;
    }
}

