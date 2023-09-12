
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;


public class J05081 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<matHang> mh = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            mh.add(new matHang("MH" + String.format("%03d", i + 1), sc.nextLine(), sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(mh, new SortByProfit());
        for(matHang x:mh){
            System.out.println(x);
        }
    }
}

class matHang {
    private String maMH, tenMH, donVi;
    private int giaMua, giaBan;

    public matHang() {
    }

    public matHang(String maMH, String tenMH, String donVi, int giaMua, int giaBan) {
        this.maMH = maMH;
        this.tenMH = tenMH;
        this.donVi = donVi;
        this.giaMua = giaMua;
        this.giaBan = giaBan;
    }

    public int profit() {
        return this.giaBan - this.giaMua;
    }

    public String getMaMH() {
        return this.maMH;
    }

    public String toString() {
        return this.maMH + " " + this.tenMH + " " + this.donVi + " " + this.giaMua + " " + this.giaBan + " " + profit();
    }
}

class SortByProfit implements Comparator<matHang> {
    public int compare(matHang mh1, matHang mh2) {
        if (mh1.profit() != mh2.profit()) {
            if (mh1.profit() < mh2.profit())
                return 1;
            else return -1;
        }else{
            return mh1.getMaMH().compareTo(mh2.getMaMH());
        }
    }
}

