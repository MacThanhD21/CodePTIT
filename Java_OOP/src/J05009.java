
import java.util.*;

public class J05009 {
    static class ThiSinh {
        private int id;
        private String name, date;
        private double d1, d2, d3;

        // Constructor
        public ThiSinh(int id, String name, String date, double d1, double d2, double d3) {
            this.id = id;
            this.name = name;
            this.date = date;
            this.d1 = d1;
            this.d2 = d2;
            this.d3 = d3;
        }

        public double getDiemTong(){
            return this.d1 + this.d2 + this.d3;
        }

    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.date + " " + this.getDiemTong();
    }

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        double ThuKhoa = 0;
        ArrayList<ThiSinh> arr = new ArrayList<>();
        for(int i = 0; i < n; i++){
            sc.nextLine();
            String name = sc.nextLine();
            String date = sc.nextLine();
            ThiSinh s = new ThiSinh(i + 1, name, date, sc.nextDouble(), sc.nextDouble(), sc.nextDouble());
            ThuKhoa = Math.max(ThuKhoa, s.getDiemTong());
            arr.add(s);
        }

        Collections.sort(arr, new Comparator<ThiSinh>() {
            @Override
            public int compare(ThiSinh o1, ThiSinh o2) {
                return (int) (o1.getDiemTong() - o2.getDiemTong());
            }
        });

        for(ThiSinh x : arr){
            if(x.getDiemTong() == ThuKhoa){
                System.out.println(x);
            }
        }
    }
}
