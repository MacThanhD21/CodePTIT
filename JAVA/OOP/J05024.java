
import java.util.ArrayList;
import java.util.Scanner;

public class J05024 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<sinhVien> sv = new ArrayList<>();
        int n = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            sv.add(new sinhVien(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String nganh = sc.nextLine().toUpperCase();
            System.out.println("DANH SACH SINH VIEN NGANH " + nganh + ":");
            for (sinhVien x : sv) {
                if (x.getNganh().equalsIgnoreCase(nganh)) {
                    System.out.println(x);
                }
            }
        }
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

    public String getNganh(){
        String s = "";
        if(this.maSV.contains("DCKT"))  s = "Ke toan";
        if(this.maSV.contains("DCVT"))  s = "Vien thong";
        if(this.maSV.contains("DCDT"))  s = "Dien tu";
        if(this.maSV.contains("DCCN") && this.lop.charAt(0) != 'E')  s = "Cong nghe thong tin";
        if(this.maSV.contains("DCAT") && this.lop.charAt(0) != 'E')  s = "An toan thong tin";
        return s;
    }

    public String toString() {
        return this.maSV + " " + this.hoTen + " " + this.lop + " " + this.email;
    }
}

