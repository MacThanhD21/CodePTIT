

import java.lang.Math;
import java.util.*;

class GiangVien {
    private String id, name, khoa;
    

    public GiangVien(int id, String name, String khoa) {
        this.id = "GV" +  String.format("%02d", id);
        this.name = name;
        this.khoa = khoa;
    }
    public String getName() {
        return this.name;
    }
    public String getKhoa() {
        String[] arr = this.khoa.toUpperCase().split("\\s+");
        String res = "";

        for(String x : arr) {
            res += x.charAt(0);
        }
        
        return res;
    }

    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.getKhoa();
    }
}
        
public class J05027 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<GiangVien> arr = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            arr.add(new GiangVien(i + 1, sc.nextLine(), sc.nextLine()));
        }

        int q = Integer.parseInt(sc.nextLine());
        while(q--> 0) {

            String key = sc.nextLine();
            
            System.out.println("DANH SACH GIANG VIEN THEO TU KHOA " + key + ": ");
            
            for(GiangVien x : arr) {
                if (x.getName().toUpperCase().contains(key.toUpperCase())) {
                    System.out.println(x);
                }
            }
        }
    }
}