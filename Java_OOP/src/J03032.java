
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
        
public class J03032 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test = 1;
        test = Integer.parseInt(sc.nextLine());

        while(test--> 0){
            String a[] = sc.nextLine().split("\\s+");
            String tmp = "";

            for(String x : a) {
                StringBuilder sb = new StringBuilder(x);
                tmp += sb.reverse().toString();
                tmp += " ";
            }
            tmp.trim();
            System.out.println(tmp);

        }
    }
}