package OOP;


import java.util.ArrayList;
import java.util.Scanner;

public class J05057 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<thiSinh> ts = new ArrayList<>();
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            sc.nextLine();
            ts.add(new thiSinh(sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble()));
        }
        for(thiSinh x:ts){
            System.out.println(x);
        }
    }
}


class thiSinh {
    private String maThiSinh, hoTen;
    private double diemToan, diemLy, diemHoa;

    public thiSinh() {
    }

    public thiSinh(String maThiSinh, String hoTen, double diemToan, double diemLy, double diemHoa) {
        this.maThiSinh = maThiSinh;
        this.hoTen = hoTen;
        this.diemToan = diemToan;
        this.diemLy = diemLy;
        this.diemHoa = diemHoa;
    }

    public int khuVuc() {
        String tmp = "";
        tmp += this.maThiSinh.charAt(2);
        return Integer.parseInt(tmp);
    }

    public double tongDiem() {
        return this.diemToan * 2 + this.diemLy + this.diemHoa;
    }

    @Override
    public String toString() {
        String res = "";
        int tmp = 0;
        double uuTien;
        if (khuVuc() == 1) {
            uuTien = 0.5;
        } else if (khuVuc() == 2) {
            uuTien = 1.0;
        } else {
            uuTien = 2.5;
        }
        if (tongDiem() + uuTien >= 24.0) {
            res += "TRUNG TUYEN";
        } else {
            res += "TRUOT";
        }
        if (khuVuc() == 2) {
            if (tongDiem() == (int) tongDiem()) {
                tmp = (int) tongDiem();
                return this.maThiSinh + " " + this.hoTen + " " + 1 + " " + tmp + " " + res;
            } else {
                return this.maThiSinh + " " + this.hoTen + " " + 1 + " " + String.format("%.1f", tongDiem()) + " " + res;
            }
        } else {
            if (khuVuc() == 1) {
                if (tongDiem() == (int) tongDiem()) {
                    tmp = (int) tongDiem();
                    return this.maThiSinh + " " + this.hoTen + " " + "0.5" + " " + tmp + " " + res;
                } else {
                    return this.maThiSinh + " " + this.hoTen + " " + "0.5" + " " + String.format("%.1f", tongDiem()) + " " + res;
                }
            } else {
                if (tongDiem() == (int) tongDiem()) {
                    tmp = (int) tongDiem();
                    return this.maThiSinh + " " + this.hoTen + " " + "2.5" + " " + tmp + " " + res;
                } else {
                    return this.maThiSinh + " " + this.hoTen + " " + "2.5" + " " + String.format("%.1f", tongDiem()) + " " + res;
                }
            }
        }
    }
}

