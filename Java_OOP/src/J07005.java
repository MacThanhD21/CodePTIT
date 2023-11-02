package Javaa;

import java.io.DataInput;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class J07005 {
    public static void main(String[] args) throws IOException {
        DataInputStream in = new DataInputStream(new FileInputStream("DATA.IN"));

        int[] a = new int[1005];

        for (int i = 0; i < 100000; i++) {
            a[in.readInt()]++;
        }

        for (int i = 0; i < 1005; i++) {
            if (a[i] > 0) {
                System.out.println(i + " " + a[i]);
            }
        }
        in.close();
    }
}
