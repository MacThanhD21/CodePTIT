
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
        
public class J03027 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test = 1;
        // test = Integer.parseInt(sc.nextLine());

        while(test--> 0){
            String s = sc.nextLine();
            Stack<Character> st = new Stack<>();

            for(Character c : s.toCharArray()) {
                if (!st.isEmpty() && st.peek() == c) {
                    st.pop();
                }
                else {
                    st.push(c);
                }
            }

            StringBuilder sb = new StringBuilder();
            for(Character x : st) {
                sb.append(x);
            }

            System.out.println(sb.toString().length() > 0 ? sb.toString() : "Empty String"); 
        }
    }
}