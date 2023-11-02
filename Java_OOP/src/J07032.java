package Javaa;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class J07032 {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
        ObjectInputStream in1 = new ObjectInputStream(new FileInputStream("DATA1.in"));

        ObjectInputStream in2 = new ObjectInputStream(new FileInputStream("DATA2.in"));

        int a[] = new int[1005];

        ArrayList<Integer> a1 = (ArrayList<Integer>) in1.readObject();

        ArrayList<Integer> a2 = (ArrayList<Integer>) in2.readObject();

        Set<Integer> se1 = new HashSet<>(a1);
        Set<Integer> se2 = new HashSet<>(a2);

        for (Integer x : a1) {
            if (check(x)) {
                a[x]++;
            }
        }
        for (Integer x : a2) {
            if (check(x)) {
                a[x]++;
            }
        }
        for (int i = 0; i < 100005; i++) {
            if (a[i] > 0 && se1.contains(i) && se2.contains(i)) {
                System.out.println(i + " " + a[i]);
            }
        }
    }

    public static boolean check(int n) {
        String s = n + "";
        String r_s = new StringBuilder(s).reverse().toString();

        if (s.length() % 2 == 0 || s.length() == 1) {
            return false;
        }
        for (char x : s.toCharArray()) {
            if (Character.getNumericValue(x) % 2 == 0) {
                return false;
            }
        }
        if (r_s.compareTo(s) != 0) {
            return false;
        }
        return true;
    }
}
