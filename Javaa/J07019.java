import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Product {
    private String id, name;
    private int first_Type, second_Type;

    public Product(String id, String name, int first_Type, int second_Type) {
        this.id = id;
        this.name = name;
        this.first_Type = first_Type;
        this.second_Type = second_Type;
    }


    public String getId() {
        return this.id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getFirst_Type() {
        return this.first_Type;
    }

    public void setFirst_Type(int first_Type) {
        this.first_Type = first_Type;
    }

    public int getSecond_Type() {
        return this.second_Type;
    }

    public void setSecond_Type(int second_Type) {
        this.second_Type = second_Type;
    }
}

class Bill {
    private String id;
    private int quantity;
    public Product product;
    public static int cnt = 1;
    
    public Bill(String id, int quantity, ArrayList<Product> products) {
        this.id = id;
        this.quantity = quantity;
        for(Product x : products) {
            if(x.getId().equals(this.id.substring(0, this.id.length() - 1))) {
                this.product = x;
                break;
            }
        }
    }
 
    public int getTotalBill() {
        if(this.id.substring(2).equals("1")) {
            return this.quantity * this.product.getFirst_Type();
        }
        else{
            return this.quantity * this.product.getSecond_Type();
        }
    }

    public int getDiscount() {
        if(this.quantity >= 150) {
            return (int) (0.5 * this.getTotalBill());
        }
        else if(this.quantity >= 100) {
            return (int) (0.3 * this.getTotalBill());
        }
        else if(this.quantity >= 50) {
            return (int) (0.15 * this.getTotalBill());
        }
        else {
            return 0;
        }
    }


    @Override
    public String toString() {
        String new_Id = this.id + "-" + String.format("%03d", cnt++);
        return new_Id + " " + this.product.getName() + " " + this.getDiscount() + " " + (this.getTotalBill() - this.getDiscount());
    }
}

public class J07019 {
    public static void main(String[] args) throws FileNotFoundException{
        // Scanner sc = new Scanner(System.in);
        Scanner sc = new Scanner(new File("DATA1.in"));
        int n = Integer.parseInt(sc.nextLine());

        ArrayList <Product> arr1 = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            arr1.add(new Product(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        }

        sc = new Scanner(new File("DATA2.in"));
        n = Integer.parseInt(sc.nextLine());

        ArrayList <Bill> arr2 = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            arr2.add(new Bill(sc.next(), Integer.parseInt(sc.nextLine().substring(1)), arr1));
        }

        // Collections.sort(arr2);

        for(Bill x : arr2) {
            System.out.println(x);
        }
    }
}