package FIleProcess;

import java.util.*;
import java.io.*;

public class J07002 {
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(new File("DATA.in"));

        long sum = 0;
        while(sc.hasNextLine()){
            String s = sc.next();

            try {
                sum += Integer.parseInt(s);
            } catch (Exception e){
                
            }
        }

        System.out.println(sum);
    }
}
