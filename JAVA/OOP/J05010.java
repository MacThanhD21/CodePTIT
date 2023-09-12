package OOP;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;

public class J05010 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<matHang> mh = new ArrayList<>();
        for(int i=0;i<n;i++){
            sc.nextLine();
            mh.add(new matHang(String.format("%01d",i+1), sc.nextLine(),sc.nextLine(),sc.nextDouble(),sc.nextDouble()));
        }
        Collections.sort(mh, new SortMH());
        for(matHang x:mh){
            System.out.println(x);
        }
    }
}
class matHang {
    private String maMH, tenMH, nhomMH;
    private double giaMua, giaBan;

    public matHang() {
    }

    public matHang(String maMH, String tenMH, String nhomMH, double giaMua, double giaBan) {
        this.maMH = maMH;
        this.tenMH = tenMH;
        this.nhomMH = nhomMH;
        this.giaMua = giaMua;
        this.giaBan = giaBan;
    }

    public double loiNhuan() {
        return this.giaBan - this.giaMua;
    }

    public String toString() {
        return this.maMH + " " + this.tenMH + " " + this.nhomMH + " " + String.format("%.2f", loiNhuan());
    }
}


class SortMH implements Comparator<matHang> {
    public int compare(matHang mh1, matHang mh2){
        if(mh1.loiNhuan()<mh2.loiNhuan()){
            return 1;
        }else return -1;
    }
}

