import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;
import java.util.Map;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.*;

class NhanVien {
    private String id, name, sec, DOB, add, code, reDate;

    NhanVien(int id, String name, String sec, String DOB, String add, String code, String reDate) {
        this.id = String.format("%05d", id);
        this.name = name;
        this.sec = sec;
        this.DOB = DOB;
        this.add = add;
        this.code = code;
        this.reDate = reDate;
    }

    public String getId() {
        return this.id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSec() {
        return this.sec;
    }

    public void setSec(String sec) {
        this.sec = sec;
    }

    public String getDOB() {
        return this.DOB;
    }

    public void setDOB(String DOB) {
        this.DOB = DOB;
    }

    public String getAdd() {
        return this.add;
    }

    public void setAdd(String add) {
        this.add = add;
    }

    public String getCode() {
        return this.code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public String getReDate() {
        return this.reDate;
    }

    public void setReDate(String reDate) {
        this.reDate = reDate;
    }

    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.sec + " " + this.DOB
                + " " + this.add + " " + this.code + " " + this.reDate;
    }
}

class SortByDate implements Comparator<NhanVien> {

    @Override
    public int compare(NhanVien o1, NhanVien o2) {

        int tmp1 = Integer.parseInt((o1.getDOB().substring(6) + o1.getDOB().substring(3, 5) + o1.getDOB().substring(0, 2)));
        int tmp2 = Integer.parseInt((o2.getDOB().substring(6) + o2.getDOB().substring(3, 5) + o2.getDOB().substring(0, 2)));

        if (tmp1 < tmp2) return -1;
        else return 1;
    }
}

public class J05007 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());
        ArrayList<NhanVien> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            NhanVien x = new NhanVien(i + 1, sc.nextLine(), sc.nextLine(), sc.nextLine(),
                    sc.nextLine(), sc.nextLine(), sc.nextLine());

            arr.add(x);
        }
        Collections.sort(arr, new SortByDate());

        for (NhanVien x : arr) {
            System.out.println(x);
        }
        sc.close();
    }
}