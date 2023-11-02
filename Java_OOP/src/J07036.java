
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class SinhViennnnnn {
    private String maSV, tenSV, clas, email;

    public String getMaSV() {
        return this.maSV;
    }

    public String getTenSV() {
        return this.tenSV;
    }

    public String getClas() {
        return this.clas;
    }

    public String getEmail() {
        return this.email;
    }


    public SinhViennnnnn(Scanner sc) {
        this.maSV = sc.next();
        sc.nextLine();
        this.tenSV = standardName(sc.nextLine());
        this.clas = sc.next();
        this.email = sc.next();
    }

    public static String standardName(String s) {
        s = s.trim().toLowerCase();
        String[] tmp = s.split("\\s+");
        String res = "";
        for (String x : tmp) {
            res += Character.toUpperCase(x.charAt(0)) + x.substring(1) + " ";
        }
        return res.trim();
    }
}

class MonHoc {
    private String maMH, tenMH;
    private int soTinChi;


    public MonHoc(Scanner sc) {
        this.maMH = sc.next();
        sc.nextLine();
        this.tenMH = sc.nextLine();
        this.soTinChi = sc.nextInt();
    }

    public String getMaMH() {
        return this.maMH;
    }

    public String getTenMH() {
        return this.tenMH;
    }

    public int getSoTinChi() {
        return this.soTinChi;
    }
}

class BangDiem implements Comparable<BangDiem> {
    private double diem;
    private SinhViennnnnn sv;
    private MonHoc mh;

    public BangDiem(Scanner sc, ArrayList<SinhViennnnnn> dsSV, ArrayList<MonHoc> dsMH) {
        String maSV = sc.next();
        String maMH = sc.next();
        this.diem = sc.nextDouble();
        for (SinhViennnnnn tmp : dsSV) {
            if (tmp.getMaSV().contains(maSV)) {
                this.sv = tmp;
                break;
            }
        }
        for (MonHoc tmp : dsMH) {
            if (tmp.getMaMH().contains(maMH)) {
                this.mh = tmp;
                break;
            }
        }
    }
    public double getDiem() {
        return this.diem;
    }

    public SinhViennnnnn getSv() {
        return this.sv;
    }

    public MonHoc getMh() {
        return this.mh;
    }
    @Override
    public String toString() {
        String diem = String.format("%.1f", this.diem);
        if (this.diem == (int) this.diem) {
            diem = String.format("%.0f", this.diem);
        }
        return this.sv.getMaSV() + ' ' + this.sv.getTenSV() + ' ' + this.mh.getMaMH() + " " + this.mh.getTenMH() + ' ' + diem;
    }

    @Override
    public int compareTo(BangDiem o) {
        if (this.mh.getMaMH().compareTo(o.mh.getMaMH()) != 0) {
            return this.mh.getMaMH().compareTo(o.mh.getMaMH());
        }
        return this.sv.getMaSV().compareTo(o.sv.getMaSV());
    }
}

public class J07036 {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        int t = sc.nextInt();
        ArrayList<SinhViennnnnn> dsSV = new ArrayList<>();
        while (t-- > 0) {
            dsSV.add(new SinhViennnnnn(sc));
        }

        sc = new Scanner(new File("MONHOC.in"));
        t = sc.nextInt();
        ArrayList<MonHoc> dsMH = new ArrayList<>();
        while (t-- > 0) {
            dsMH.add(new MonHoc(sc));
        }

        sc = new Scanner(new File("BANGDIEM.in"));
        t = sc.nextInt();
        ArrayList<BangDiem> dsBD = new ArrayList<>();
        while (t-- > 0) {
            dsBD.add(new BangDiem(sc, dsSV, dsMH));
        }
        Collections.sort(dsBD);
        t = sc.nextInt();
        while (t-- > 0) {
            String clas_name = sc.next();
            for (SinhViennnnnn tmp : dsSV) {
                if (tmp.getClas().equals(clas_name)) {
                    System.out.println("BANG DIEM lop " + tmp.getClas() + ":");
                    break;
                }
            }
                
            for (BangDiem tmp : dsBD) {
                if (tmp.getSv().getClas().equals(clas_name)) {
                    System.out.println(tmp);
                }
            }
        }
    }
}