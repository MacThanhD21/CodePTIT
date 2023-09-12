import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class SinhVien {
    private String id, name, lop, mail;

    public SinhVien(String id, String name, String lop, String mail) {
        this.id = id;
        this.name = name;
        this.lop = lop;
        this.mail = mail;
    }

    public void chuanHoa() {
        String[] arr = this.name.split("\\s+");
        StringBuilder res = new StringBuilder();
        for (String x : arr) {
            res.append(Character.toUpperCase(x.charAt(0)))
               .append(x.substring(1).toLowerCase())
               .append(" ");
        }
        this.name = res.toString().trim();
    }

    public String getId() {
        return this.id;
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

    public static void main(String[] args) {
        // try {
            // Scanner sc = new Scanner(new File("SINHVIEN.in"));
            Scanner sc = new Scanner(System.in);
            int n = Integer.parseInt(sc.nextLine());

            ArrayList<SinhVien> arr = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                int cnt = 0;
                String s = "";
                while(sc.hasNextLine()) {
                    cnt++;
                    s = sc.nextLine();
                    if(cnt == 4) break;
                }
            }

            Collections.sort(arr, new SortById());
            
            for (SinhVien x : arr) {
                System.out.println(x);
            }
        // } catch (FileNotFoundException e) {
        //     e.printStackTrace();
        // }
    }
}
