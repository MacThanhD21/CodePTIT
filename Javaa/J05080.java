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
    public String getName_GV() {
        return this.name_GV;
    }
    @Override
    public String toString() {
        return this.id + " " + this.lop + " " + this.gr;
    }
}
public class J05080 {
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
                if(o1.getId().compareTo(o2.getId()) != 0) {
                    return o1.getId().compareTo(o2.getId());
                } else {
                    return o1.getGr().compareTo(o2.getGr());
                }
            }
        });

        int q = Integer.parseInt(sc.nextLine());

        while(q-- >0 ) {
            String s = sc.nextLine();
            String name_GV = "";
            for(HocPhan x : arr) {
                if(x.getName_GV().equals(s)) {
                    // System.out.println(x);
                    name_GV = x.getName_GV();
                    break;
                }
            }

            System.out.println("Danh sach cho giang vien " + name_GV + ":");

            for(HocPhan x : arr) {
                if(x.getName_GV().equals(s)) {
                    System.out.println(x);
                }
            }
        }
        sc.close();
    }
}