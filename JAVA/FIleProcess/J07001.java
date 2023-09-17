package FIleProcess;

import java.io.File;
import java.io.IOException;
import java.util.*;


public class J07001 {
    public static void main(String[] args) {

        try {
            Scanner sc = new Scanner (new File("DATA.in"));
            while (sc.hasNextLine()){
                System.out.println(sc.nextLine());
                
            }
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
