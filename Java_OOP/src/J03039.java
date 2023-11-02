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
import java.math.BigInteger;
import java.util.*;
        
public class J03039 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test = 1;
        test = Integer.parseInt(sc.nextLine());

        while(test--> 0){
            String a = sc.next();
            String b = sc.next();

            BigInteger Big1 = new BigInteger(a);
            BigInteger Big2 = new BigInteger(b);

            BigInteger mod1 = Big1.mod(Big2);
            BigInteger mod2 = Big2.mod(Big1);

            if (mod1.equals(BigInteger.ZERO) || mod2.equals(BigInteger.ZERO)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}