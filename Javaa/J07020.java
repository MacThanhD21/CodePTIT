import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

class Customer {
    private String id, name, gender, DOB, add;


    public Customer(int id, String name, String gender, String DOB, String add) {
        this.id = "KH" + String.format("%03d", id);
        this.name = name;
        this.gender = gender;
        this.DOB = DOB;
        this.add = add;
    }


    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public String getGender() {
        return this.gender;
    }

    public String getDOB() {
        return this.DOB;
    }

    public String getAdd() {
        return this.add;
    }
}

class Item {
    private String id, name, calc_Unit;
    private int pur_Price, Price;


    public Item(int id, String name, String calc_Unit, int pur_Price, int Price) {
        this.id = "MH" + String.format("%03d", id);
        this.name = name;
        this.calc_Unit = calc_Unit;
        this.pur_Price = pur_Price;
        this.Price = Price;
    }

    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }
    public String getCalc_Unit() {
        return this.calc_Unit;
    }

    public int getPur_Price() {
        return this.pur_Price;
    }
    public int getPrice() {
        return this.Price;
    }
}

class Bill {
    private String id_Bill, id_Cus, id_Item;
    private int quantity;
    public Customer customer;
    public Item item;

    public Bill(int id_Bill, String id_Cus, String id_Item, int quantity, ArrayList<Customer> customers, ArrayList<Item> items) {
        this.id_Bill = "HD" + String.format("%03d", id_Bill);
        this.id_Cus = id_Cus;
        this.id_Item = id_Item;
        this.quantity = quantity;

        for(Customer x : customers) {
            if(x.getId().equals(this.id_Cus)) {
                this.customer = x;
                break;
            }
        }
        for(Item x : items) {
            if(x.getId().equals(this.id_Item)) {
                this.item = x;
                break;
            }
        }
    }

    public int getTotalMoney() {
        return this.quantity * this.item.getPrice();
    }


    @Override
    public String toString() {
        return this.id_Bill 
        + " " + this.customer.getName() 
        + " " + this.customer.getAdd() 
        + " " + this.item.getName() 
        + " " + this.item.getCalc_Unit() 
        + " " + this.item.getPur_Price() 
        + " " + this.item.getPrice() 
        + " " + this.quantity 
        + " " + this.getTotalMoney();
    }

}

public class J07020 {
    public static void main(String[] args) throws FileNotFoundException{
        // Scanner sc = new Scanner(System.in);
        Scanner sc = new Scanner(new File("KH.in"));

        int n = Integer.parseInt(sc.nextLine());

        ArrayList <Customer> Cus_List = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            Cus_List.add(new Customer(i + 1, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("MH.in"));
        n = Integer.parseInt(sc.nextLine());

        ArrayList <Item> Item_List = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            Item_List.add(new Item(i + 1, sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        }

        sc = new Scanner(new File("HD.in"));
        n = Integer.parseInt(sc.nextLine());

        ArrayList <Bill> Bill_List = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            String s = sc.nextLine().trim();
            String[] tmp = s.split("\\s+");
            String id_Cus = tmp[0];
            String id_Item = tmp[1];
            int quantity = Integer.parseInt(tmp[2]);
            Bill_List.add(new Bill(i + 1, id_Cus, id_Item, quantity, Cus_List, Item_List));
        }
        
        for(Bill x : Bill_List) {
            System.out.println(x);
        }
    }
}
