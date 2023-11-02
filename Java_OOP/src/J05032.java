import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;
import java.util.Map;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.*;
        
class OldYoung {
    private String name, DOB;

    public OldYoung(String name, String DOB) {
        this.name = name;
        this.DOB = DOB;
    }
    
    public String getName() {
        return this.name;
    } 
    public String getDOB() {
        return this.DOB;
    }

    @Override
    public String toString() {
        return this.getName() + " " + this.getDOB();
    }
}

class SortByDOB implements Comparator<OldYoung> {

    @Override
    public int compare(OldYoung o1, OldYoung o2) {
        int tmp1 = Integer.parseInt((o1.getDOB().substring(6) + o1.getDOB().substring(3, 5) + o1.getDOB().substring(0, 2)));
        int tmp2 = Integer.parseInt((o2.getDOB().substring(6) + o2.getDOB().substring(3, 5) + o2.getDOB().substring(0, 2)));

        if (tmp1 < tmp2) return -1;
        else return 1;
    }

}
public class J05032 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<OldYoung> arr = new ArrayList<>();
        for(int i = 1; i <= n; i++) {
            arr.add(new OldYoung(sc.next(), sc.next()));
        }

        Collections.sort(arr, new SortByDOB());
        
        System.out.println(arr.get(arr.size() - 1).getName());
        System.out.println(arr.get(0).getName());
        sc.close();
    }
}