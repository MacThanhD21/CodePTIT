import java.io.*;
import java.util.*;

class SinhVien {
    private String id, name, lop, mail;

    public SinhVien(String id, String name, String lop, String mail) {
        this.id = id;
        this.name = name;
        this.lop = lop;
        this.mail = mail;
    }
    
    public void chuanHoa(){
        String[] arr = this.name.split("\\s+");
        String res = "";
        for(String x : arr) {
            res += Character.toUpperCase(x.charAt(0));
            for(int j = 1; j < x.length(); j++) {
                res += Character.toLowerCase(x.charAt(j));
            }
            res += " ";
        }
        this.name = res.trim();
    }

    public String getId() {
        return this.id;
    }

    public String getLop() {
        return this.lop;
    }

    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.lop + " " + this.mail;
    }
}

class SortById implements Comparator<SinhVien> {
    @Override
    public int compare(SinhVien o1, SinhVien o2) {
        return o1.getId().compareTo(o2.getId());
    }
}

public class J07033 {
    
    public static void main(String[] args) throws FileNotFoundException{
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        // Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<SinhVien> arr = new ArrayList<>();

        for(int i = 1; i <= n; i++) {
            SinhVien x = new SinhVien(sc.nextLine().trim(), sc.nextLine().trim(), sc.nextLine().trim(), sc.nextLine().trim());
            x.chuanHoa();
            arr.add(x);
        }

        Collections.sort(arr, new SortById());
        for(SinhVien x : arr) {
            System.out.println(x);
        }
    }
}