
import java.util.*;
        
class Grocery {
    private String id, name, unit_calc;
    private int import_Price, nums;


    public Grocery(int id, String name, String unit_calc, int import_Price, int nums) {
        this.id = "MH" + String.format("%02d", id);
        this.name = name;
        this.unit_calc = unit_calc;
        this.import_Price = import_Price;
        this.nums = nums;
    }

    public int getTransportPrice() {
        return (int)(Math.round(this.import_Price * nums * 0.05));
    }

    public int getTotal() {
        return this.import_Price * nums + this.getTransportPrice();
    }

    public int getSellPrice() {
        int result = (this.getTotal() + (int)(Math.round(this.getTotal() * 0.02))) / nums;
        return (int)(Math.ceil(result / 100.0)) * 100;
    }

    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.unit_calc +  " " + this.getTransportPrice() + " " + this.getTotal() + " " + this.getSellPrice();
    }
}

public class J05036 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        
        ArrayList<Grocery> arr = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Grocery(i + 1, sc.nextLine(), sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }

        Collections.sort(arr, new Comparator<Grocery>() {

            @Override
            public int compare(Grocery o1, Grocery o2) {
                return o2.getSellPrice() - o1.getSellPrice();
            }
        });

        for(Grocery x : arr ) {
            System.out.println(x);
        }
    }
}