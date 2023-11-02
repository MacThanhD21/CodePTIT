import java.util.ArrayList;
import java.util.Scanner;

class CLB {
    private String idCLB, name;
    private int giaVe;

    public CLB(String idCLB, String name, int giaVe) {
        this.idCLB = idCLB;
        this.name = name;
        this.giaVe = giaVe;
    }

    public String getIdCLB() {
        return idCLB;
    }

    public void setIdCLB(String idCLB) {
        this.idCLB = idCLB;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getGiaVe() {
        return giaVe;
    }

    public void setGiaVe(int giaVe) {
        this.giaVe = giaVe;
    }
}

class TranDau {
    private String id;
    private CLB clb;
    private long soVe, doanhThu;

    TranDau(String id, long soVe, ArrayList<CLB> dsCLB) {
        this.id = id;
        this.soVe = soVe;
        for (CLB tmp : dsCLB) {
            if (this.id.substring(1, 3).equals(tmp.getIdCLB())) {
                this.clb = tmp;
                break;
            }
        }
        this.doanhThu = this.clb.getGiaVe() * this.soVe;
    }

    @Override
    public String toString() {
        return this.id + " " + this.clb.getName() + " " + this.doanhThu;
    }
}

public class J05070 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<CLB> dsCLB = new ArrayList<>();
        while (n-- > 0) {
            sc.nextLine();
            dsCLB.add(new CLB(sc.nextLine(), sc.nextLine(), sc.nextInt()));
        }
        int m = sc.nextInt();
        ArrayList<TranDau> dsTD = new ArrayList<>();
        while (m-- > 0) {
            dsTD.add(new TranDau(sc.next(), sc.nextLong(), dsCLB));
        }
        for (TranDau tmp : dsTD) {
            System.out.println(tmp);
        }
    }
}