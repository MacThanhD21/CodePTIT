import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Person implements Comparable<Person> {
    private String tenFull, tenChinh, ho_Dem;

    public Person(Scanner sc) {
        this.tenFull = chuanHoa(sc.nextLine().trim().toLowerCase());
    }

    public String chuanHoa(String s) {
        String[] arr = s.split("\\s+");
        String res = "";
        for (String x : arr) {
            res += Character.toUpperCase(x.charAt(0)) + x.substring(1).toLowerCase() + " ";
        }
        for (String x : arr) {
            if (x != arr[arr.length - 1]) {
                this.ho_Dem += x + " ";
            }
        }
        this.ho_Dem = this.ho_Dem.trim();
        this.tenChinh = arr[arr.length - 1];
        return res;
    }

    @Override
    public String toString() {
        return this.tenFull;
    }

    @Override
    public int compareTo(Person o) {
        if (this.tenChinh.contentEquals(o.tenChinh))
            return this.tenFull.compareTo(o.tenFull);
        return this.tenChinh.compareTo(o.tenChinh);
    }
}

public class J07072 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("DANHSACH.in"));
        ArrayList<Person> dsP = new ArrayList<>();
        while (sc.hasNextLine())
            dsP.add(new Person(sc));
        Collections.sort(dsP);
        for (Person tmp : dsP) {
            System.out.println(tmp);
        }
    }
}