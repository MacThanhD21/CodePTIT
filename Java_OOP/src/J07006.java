
import java.io.*;
import java.util.*;

public class J07006 {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
        FileInputStream in = new FileInputStream("DATA.in");

        ObjectInputStream inp = new ObjectInputStream(in);

        ArrayList<Integer> arr = (ArrayList<Integer>) inp.readObject();

        TreeMap<Integer, Integer> mp = new TreeMap<>();

        for (int x : arr) {
            if (mp.containsKey(x)) {
                mp.put(x, mp.get(x) + 1);
            } else {
                mp.put(x, 1);
            }
        }

        for (Integer x : mp.keySet()) {
            System.out.println(x + " " + mp.get(x));
        }
    }
}
