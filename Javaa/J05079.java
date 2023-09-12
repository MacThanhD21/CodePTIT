import java.util.*;
import java.util.Scanner;

class HocPhan {
    private String id, lop, gr, name_GV;


    public HocPhan(String id, String lop, String gr, String name_GV) {
        this.id = id;
        this.lop = lop;
        this.gr = gr;
        this.name_GV = name_GV;
    }

    public String getId() {
        return this.id;
    }

    public String getLop() {
        return this.lop;
    }

    public String getGr() {
        return this.gr;
    }
    @Override
    public String toString() {
        return this.gr + " " + this.name_GV;
    }
}
public class J05079 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        ArrayList<HocPhan> arr = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            arr.add(new HocPhan(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }

        Collections.sort(arr, new Comparator<HocPhan>() {

            @Override
            public int compare(HocPhan o1, HocPhan o2) {
                return o1.getGr().compareTo(o2.getGr());
            }
        });

        int q = Integer.parseInt(sc.nextLine());

        while(q-- >0 ) {
            String s = sc.nextLine();
            String subJ = "";
            for(HocPhan x : arr) {
                if(x.getId().equals(s)) {
                    // System.out.println(x);
                    subJ = x.getLop();
                    break;
                }
            }

            System.out.println("Danh sach nhom lop mon " + subJ + ":");

            for(HocPhan x : arr) {
                if(x.getId().equals(s)) {
                    System.out.println(x);
                }
            }
        }
        sc.close();
    }
}