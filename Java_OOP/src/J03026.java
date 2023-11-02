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
        
public class J03026 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test = 1;
        test = Integer.parseInt(sc.nextLine());

        while(test--> 0){
            String s = sc.nextLine();
            String t = sc.nextLine();

            if(s.equals(t)) {
                System.out.println(-1);
            }
            else {
                System.out.println(Math.max(s.length(), t.length()));
            }
        }
    }
}