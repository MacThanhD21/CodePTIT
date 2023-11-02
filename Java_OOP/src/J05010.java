package javaa;


import java.util.*;

public class J05010 {
    
    static class MatHang {
        private String id, name, Type;
        private double gb, gm;

        public MatHang(String id, String name, String Type, double gb, double gm) {
            this.id = id;
            this.name = name;
            this.Type = Type;
            this.gb = gb;
            this.gm = gm;
        }

        public String getId() {
            return id;
        }

        public void setId(String id) {
            this.id = id;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getType() {
            return Type;
        }

        public void setType(String Type) {
            this.Type = Type;
        }

        public double getGb() {
            return gb;
        }

        public void setGb(int gb) {
            this.gb = gb;
        }

        public double getGm() {
            return gm;
        }

        public void setGm(int gm) {
            this.gm = gm;
        }
        
        public double getProfit() {
            return this.gm - this.gb;
        }
        
        @Override
        public String toString() {
            return this.id + " " + this.name + " " + this.Type + " "
                     + String.format("%.2f", this.getProfit());
        }
        
        
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        
        ArrayList<MatHang> arr = new ArrayList<>();
        
        for (int i = 0; i < n; i++){
            sc.nextLine();
            arr.add(new MatHang("" + (i + 1), sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble()));
        }
        
        Collections.sort(arr, new Comparator<MatHang>() {
            @Override
            public int compare(MatHang o1, MatHang o2) {
                return (int) (o2.getProfit() - o1.getProfit());
            }
        });
        
        for(MatHang x : arr){
            System.out.println(x);
        }
    }
}
