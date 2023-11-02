import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class J07040 {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException{
        ObjectInputStream ip1 = new ObjectInputStream(new FileInputStream("NHIPHAN.in"));
        HashSet<String> se1 = new HashSet<>();
        ArrayList<String> arr = (ArrayList<String>) ip1.readObject();

        for(String i : arr){
            String [] tmp = i.split("\\s+");
            for(String j : tmp){
                se1.add(j.toLowerCase());
            }
        }

        Scanner sc = new Scanner(new File("VANBAN.in"));

        HashSet<String> se2 = new HashSet<>();

        while(sc.hasNext()) {
            String s = sc.next().toLowerCase();
            if(se1.contains(s) && !se2.contains(s)){
                System.out.println(s);
                se2.add(s);
            }
        }
    }
}