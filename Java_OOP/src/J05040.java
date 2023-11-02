
import java.util.*;

class company {
    private String id, name, position;
    private int date_salary, num_date;


    public company(int id, String name, int date_salary, int num_date, String position) {
        this.id = "NV" + String.format("%02d", id);
        this.name = name;
        this.date_salary = date_salary;
        this.num_date = num_date;
        this.position = position;
    }

    public int getMonSalary() {
        return this.date_salary * num_date;
    }

    public int getPrize() {
        int n = num_date;
        if(n >= 25) return (int)(this.getMonSalary() * 0.2);
        else if(n >= 22) return (int)(this.getMonSalary() * 0.1);
        else return 0;
    }

    public int getPosition_Allowance() {
        if(this.position.equals("GD")) return 250000;
        else if(this.position.equals("PGD")) return 200000;
        else if(this.position.equals("TP")) return 180000;
        else return 150000;                              
    }

    public int getTotal() {
        return this.getMonSalary() + this.getPrize() + this.getPosition_Allowance();
    }
    
    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.getMonSalary() + " " + this.getPrize() + " " + this.getPosition_Allowance() + " " + this.getTotal();
    }
}
public class J05040 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<company> arr = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            arr.add(new company(i + 1, sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine()), sc.nextLine()));
        }

        Collections.sort(arr, new Comparator<company>() {

            @Override
            public int compare(company o1, company o2) {
                return o2.getTotal() - o1.getTotal();
            }
        });
        for(company x : arr) {
            System.out.println(x);
        }
    }
}