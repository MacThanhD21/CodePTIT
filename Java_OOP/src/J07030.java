package Javaa;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class J07030 {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
        ObjectInputStream in1 = new ObjectInputStream(new FileInputStream("DATA1.in"));

        ObjectInputStream in2 = new ObjectInputStream(new FileInputStream("DATA2.in"));

        ArrayList<Integer> a1 = (ArrayList<Integer>) in1.readObject();

        ArrayList<Integer> a2 = (ArrayList<Integer>) in2.readObject();

        HashSet<Integer> se1 = new HashSet<>(a1);

        HashSet<Integer> se2 = new HashSet<>(a2);

        for (int i = 0; i < 500000; i++) {
            if (se2.contains(1000000 - i) && se1.contains(i)
                    && isPrime(i) && isPrime(1000000 - i)) {
                System.out.println(i + " " + (1000000 - i));
            }
        }

        in1.close();
        in2.close();
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
