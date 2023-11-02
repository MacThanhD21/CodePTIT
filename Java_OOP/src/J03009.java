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
        
public class J03009 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = 1;
        t = Integer.parseInt(sc.nextLine());

        while(t--> 0){
            String a1[] = sc.nextLine().split("\\s+");

            String a2[] = sc.nextLine().split("\\s+");

            TreeSet<String> se1 = new TreeSet<>();
            TreeSet<String> se2 = new TreeSet<>();

            for(String x : a1){
                se1.add(x);
            }
            for(String x : a2){
                se2.add(x);
            }
            
            for(String x : se1){
                if (se2.contains(x)) {
                    continue;
                }
                else{
                    System.out.print(x + " ");
                }
            }
            System.out.println();
        }

        sc.close();
    }
}