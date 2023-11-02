
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class J05082 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        ArrayList<KhachHang> ds = new ArrayList<>();
        for (int i = 0; i < t; i++) {
            ds.add(new KhachHang(i + 1, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(ds);
        for (KhachHang tmp : ds) {
            System.out.println(tmp);
        }
    }
}

class KhachHang implements Comparable<KhachHang> {
    private String id, name, sex, address;
    private Date birthday;

    public KhachHang(int id, String name, String sex, String birthday, String address) {
        this.id = String.format("KH%03d", id);
        this.name = standardName(name);
        this.sex = sex;
        try {
            this.birthday = new SimpleDateFormat("dd/MM/yyyy").parse(birthday);
        } catch (ParseException ex) {
            Logger.getLogger(KhachHang.class.getName()).log(Level.SEVERE, null, ex);
        }
        this.address = address;
    }

    public String standardName(String s) {
        s = s.trim().toLowerCase();
        String res = "" + Character.toUpperCase(s.charAt(0));
        for (int i = 1; i < s.length(); i++)
            if (Character.isLetter(s.charAt(i))) {
                if (s.charAt(i - 1) == ' ')
                    res += " " + Character.toUpperCase(s.charAt(i));
                else
                    res += s.charAt(i);
            }
        return res;
    }

    @Override
    public String toString() {
        return this.id + ' ' + this.name
                + ' ' + this.sex + ' ' + this.address
                + ' ' + new SimpleDateFormat("dd/MM/yyyy").format(this.birthday);
    }

    @Override
    public int compareTo(KhachHang o) {
        return this.birthday.compareTo(o.birthday);
    }
}
