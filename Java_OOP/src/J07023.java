package Javaa;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.TreeSet;

public class J07023 {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
        ObjectInputStream ois1 = new ObjectInputStream(new FileInputStream("DATA1.in"));
        ObjectInputStream ois2 = new ObjectInputStream(new FileInputStream("DATA2.in"));
        
        ArrayList<Integer> a = (ArrayList<Integer>) ois1.readObject();
        ArrayList<Integer> b = (ArrayList<Integer>) ois2.readObject();

        int[] freq_a = new int[100005];
        int[] freq_b = new int[100005];
        for(int x : a) {
            if(isPalindrome(x) && isPrime(x)) {
                freq_a[x]++;
            }
        }
        for(int x : b) { 
            if(isPalindrome(x) && isPrime(x)) {
                freq_b[x]++;
            }
        }

        TreeSet<Integer> c = new TreeSet<Integer>();
        for(int i = 0; i < 100005; ++i) {
            if (freq_a[i] > 0 && freq_b[i] > 0) {
                c.add(i);
            }
        }

        for(int x : c) {
            System.out.print(x + " " + freq_a[x] + " " + freq_b[x] + "\n");
        }
    }   
    public static boolean isPrime(int n) {
        if(n < 2) return false;
        for(int i = 2; i <= Math.sqrt(n); ++i) {
            if(n % i == 0) return false;
        }
        return true;
    }
    public static boolean isPalindrome(int n) {
        String s = n + "";
        return new StringBuilder(s).reverse().toString().equals(s);
    }
}
