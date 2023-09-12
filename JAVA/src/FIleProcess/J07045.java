
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class J07045 implements Comparable<J07045>{
    private String id,name;
    private int donGia;
    private double phiPhucVu;

    public J07045(String s) {
        String [] data = s.split("\\s+");
        this.id = data[0];
        this.name = data[1];
        this.donGia= Integer.parseInt(data[2]);
        this.phiPhucVu = Double.parseDouble(data[3]);
    }

    @Override
    public int compareTo(J07045 o) {
        return this.name.compareTo(o.name);
    }
    @Override
    public String toString(){
        return this.id+' '+this.name+' '+String.valueOf(this.donGia)+' '
                +String.format("%.2f", this.phiPhucVu);
    }
    public static void main(String[] args) throws IOException {
        ArrayList<J07045> ds = new ArrayList<>();
        Scanner in = new Scanner(new File("PHONG.in"));
        int n = Integer.parseInt(in.nextLine());
        while(n-->0){
            ds.add(new J07045(in.nextLine()));
        }
        Collections.sort(ds);
        for(J07045 tmp : ds){
            System.out.println(tmp);
        }
    }
    public static void main8506254(String[] args) throws IOException {
        ArrayList<J07045> ds = new ArrayList<>();
        Scanner in = new Scanner(new File("PHONG.in"));
        int n = Integer.parseInt(in.nextLine());
        while(n-->0){
            ds.add(new J07045(in.nextLine()));
        }
        Collections.sort(ds);
        for(J07045 tmp : ds){
            System.out.println(tmp);
        }
    }
}

