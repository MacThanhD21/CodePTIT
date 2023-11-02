
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


class bangDiem {
    private String maSV, tenSV, lop;
    private double diem1, diem2, diem3;

    public bangDiem() {
    }

    public bangDiem(String maSV, String tenSV, String lop, double diem1, double diem2, double diem3) {
        this.maSV = maSV;
        this.tenSV = tenSV;
        this.lop = lop;
        this.diem1 = diem1;
        this.diem2 = diem2;
        this.diem3 = diem3;
    }

    public String getMaSV() {
        return maSV;
    }

    public String toString() {
        return this.maSV + " " + this.tenSV + " " + this.lop + " " + String.format("%.1f", this.diem1) + " " + String.format("%.1f", this.diem2) + " " + String.format("%.1f", this.diem3);
    }
}


public class J05030 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        ArrayList<bangDiem> bd = new ArrayList<>();
        while (t-- > 0) {
            sc.nextLine();
            bd.add(new bangDiem(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble()));
        }
        Collections.sort(bd, new Comparator<bangDiem>() {
            @Override
            public int compare(bangDiem o1, bangDiem o2) {
                return o1.getMaSV().compareTo(o2.getMaSV());
            }
        });
        int stt = 1;
        for (bangDiem x : bd) {
            System.out.print(stt + " ");
            stt++;
            System.out.println(x);
        }
    }
}

