
import java.util.*;

class Business {
    private String id, name;
    private int num_SV;


    public Business(String id, String name, int num_SV) {
        this.id = id;
        this.name = name;
        this.num_SV = num_SV;
    }

    public String getId() {
        return this.id;
    }

    public int getNum_SV() {
        return this.num_SV;
    }

    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.num_SV;
    }
}

class SortByNum_SV implements Comparator<Business> {

    @Override
    public int compare(Business o1, Business o2) {
        if(o1.getNum_SV() != o2.getNum_SV()) {
            return o2.getNum_SV() - o1.getNum_SV();
        }
        else {
            return o1.getId().compareTo(o2.getId());
        }
    }
}


public class J05029 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();

        ArrayList<Business> arr = new ArrayList<>();

        while(n-- > 0) {
            sc.nextLine();
            arr.add(new Business(sc.nextLine(), sc.nextLine(), sc.nextInt()));
        }

        Collections.sort(arr, new SortByNum_SV());
        
        int q = sc.nextInt();
        while(q-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            System.out.println("DANH SACH DOANH NGHIEP NHAN TU " + (a + "") + " DEN " + (b + " ") + "SINH VIEN:");
            for(Business x : arr) {
                if(x.getNum_SV() >= a && x.getNum_SV() <= b){
                    System.out.println(x);
                }
            }
        }
    }
}