
import java.util.ArrayList;
import java.util.Scanner;

class GiangVien {
    private String maGV, hoTen, boMon;

    public GiangVien() {
    }

    public GiangVien(String maGV, String hoTen, String boMon) {
        this.maGV = maGV;
        this.hoTen = hoTen;
        this.boMon = boMon;
    }

    public String getMaGV() {
        return maGV;
    }

    public String getTen() {
        String res = this.hoTen.toLowerCase();
        String[] a = res.split("\\s+");
        return a[a.length - 1];
    }

    public String getMon() {
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



public class J05026 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<GiangVien> gv = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            gv.add(new GiangVien("GV" + String.format("%02d", i), sc.nextLine(), sc.nextLine()));
        }
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String s = sc.nextLine().toUpperCase();
            String res = s;
            String[] a = res.split("\\s+");
            String tmp = "";
            for (String x : a) {
                tmp += x.charAt(0);
            }
            System.out.println("DANH SACH GIANG VIEN BO MON " + tmp + ":");
            for (GiangVien x : gv) {
                if (x.getMon().compareTo(tmp) == 0) {
                    System.out.println(x);
                }
            }
        }
    }
}

