
import java.io.*;
import java.util.*;

public class J07015 {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
        ObjectInputStream in = new ObjectInputStream(new FileInputStream("SONGUYEN.in"));

        ArrayList<Integer> arr = (ArrayList<Integer>) in.readObject();

        int[] fre = new int[10000];
        for (Integer i : arr) {
            fre[i]++;
        }
        for (int i = 0; i < 10000; i++) {
            if (fre[i] > 0 && isPrime(i)) {
                System.out.println(i + " " + fre[i]);
            }
        }
    }

    public static boolean isPrime(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}
