


import java.util.*;
        
class MatHang {
    private String id, name, unit;
    private int sell_price, purchase_price;


    public MatHang(int id, String name, String unit, int sell_price, int purchase_price) {
        this.id = "MH" + String.format("%03d", id);
        this.name = name;
        this.unit = unit;
        this.sell_price = sell_price;
        this.purchase_price = purchase_price;
    }


    public String getId() {
        return this.id;
    }

    public int getBenefit() {
        return this.purchase_price - this.sell_price;
    }


    @Override
    public String toString() {
        return this.id + " " + this.name + 
        " " + this.unit + " " + this.sell_price 
        + " " + this.purchase_price + " " 
        + this.getBenefit();
    }

}

class SortByBenefit implements Comparator<MatHang> {

    @Override
    public int compare(MatHang o1, MatHang o2) {
        if(o1.getBenefit() != o2.getBenefit()) {
            return o2.getBenefit() - o1.getBenefit();
        } else {
            return o1.getId().compareTo(o2.getId());
        }
    }
}

public class J05081 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();

        ArrayList<MatHang> arr = new ArrayList<>();

        for(int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new MatHang(i, sc.nextLine(), sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }

        Collections.sort(arr, new SortByBenefit());

        for(MatHang x : arr) {
            System.out.println(x);
        }
    }
}