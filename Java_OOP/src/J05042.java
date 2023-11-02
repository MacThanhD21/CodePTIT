

import java.util.*;
    
class Rank {
    private String name;
    private int AC_pro, total_pro;

    public Rank(String name, int AC_pro, int total_pro) {
        this.name = name;
        this.AC_pro = AC_pro;
        this.total_pro = total_pro;
    }

    public String getName() {
        return this.name;
    }

    public int getAC_pro() {
        return this.AC_pro;
    }

    public int getTotal_pro() {
        return this.total_pro;
    }


    @Override
    public String toString() {
        return this.name + " " + this.AC_pro + " " + this.total_pro;
    }
}


class SortByjjDo implements Comparator<Rank> {

    @Override
    public int compare(Rank o1, Rank o2) {
        // Sort Decreasing
        if(o1.getAC_pro() > o2.getAC_pro()) return -1;
        else if(o1.getAC_pro() == o2.getAC_pro()) {
            // Sort Increasing
            if(o1.getTotal_pro() < o2.getTotal_pro()) return -1;
            else if(o1.getTotal_pro() == o2.getTotal_pro()) {
                return o1.getName().compareTo(o2.getName());
            }
            return 1;
        }
        return 1;
    }
}

public class J05042 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<Rank> arr = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            String name = sc.nextLine();
            String[] s = sc.nextLine().split("\\s+");
            int AC_pro = Integer.parseInt(s[0]);
            int total_pro = Integer.parseInt(s[1]);
            arr.add(new Rank(name, AC_pro, total_pro));
        }

        Collections.sort(arr, new SortByjjDo());

        for(Rank x : arr) {
            System.out.println(x);
        }
    }
}