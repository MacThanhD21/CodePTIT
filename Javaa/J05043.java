
import java.util.*;
        
class NhanVien {
    private String id, name, pos;
    private int lcb, nc;


    public NhanVien(int id, String name, String pos, int lcb, int nc) {
        this.id = "NV" + String.format("%02d", id);
        this.name = name;
        this.pos = pos;
        this.lcb = lcb;
        this.nc = nc;
    }

    public String getId() {
        return this.id;
    }

    public String getPos() {
        return this.pos;
    }

    public int getPosition_Allowance() {
        if(this.pos.equals("GD")) return 500;
        else if(this.pos.equals("PGD")) return 400;
        else if(this.pos.equals("TP")) return 300;
        else if(this.pos.equals("KT")) return 250;
        else return 100;
    }

    public int getMainSalary() {
        int res = this.lcb * this.nc;
        return res;
    }

    public int getAdvance() {
        int res = (int)((this.getPosition_Allowance() + this.getMainSalary()) * 2 / 3);
        res = (int)(Math.round(res / 1000.0) * 1000);
        if(res < 25000) return (int)(res);
        else return 25000;
    }

    public int getRemain() {
        return (this.getMainSalary() - this.getAdvance()) + this.getPosition_Allowance();
    }

    public int thuNhap() {
        return this.getMainSalary() + this.getPosition_Allowance();
    }

    @Override
    public String toString() {
        return  this.id + " " + this.name 
                + " " + this.getPosition_Allowance()
                + " " + this.getMainSalary() + " " + this.getAdvance()
                + " " + this.getRemain();
    }  
}

public class J05043 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<NhanVien> arr = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            arr.add(new NhanVien(i + 1, sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        }

        Collections.sort(arr, new Comparator<NhanVien>() {

            @Override
            public int compare(NhanVien o1, NhanVien o2) {
                if(o1.thuNhap() != o2.thuNhap()) {
                    return o2.thuNhap() - o1.thuNhap();
                }                
                else {
                    return o1.getId().compareTo(o2.getId());
                }
            }
        });
        for(NhanVien x : arr) {
            System.out.println(x);
        }
    }
}