
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

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNum_SV() {
        return this.num_SV;
    }

    public void setNum_SV(int num_SV) {
        this.num_SV = num_SV;
    }


    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.num_SV;
    }
}

class SortByNum_SV implements Comparator<business> {

    @Override
    public int compare(business o1, business o2) {
        if(o1.getNum_SV() != o2.getNum_SV()) {
            return o2.getNum_SV() - o1.getNum_SV();
        }
        else {
            return o1.getId().compareTo(o2.getId());
        }
    }
}


public class J05028 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();

        ArrayList<business> arr = new ArrayList<>();

        while(n-- > 0) {
            sc.nextLine();
            arr.add(new business(sc.nextLine(), sc.nextLine(), sc.nextInt()));
        }

        Collections.sort(arr, new sortByNumSV());

        for(business x : arr) {
            System.out.println(x);
        }

    }
}