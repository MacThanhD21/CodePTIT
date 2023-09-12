package OOP;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Comparator;

class bangXH {
    private String name;
    private int AC, submit;

    public bangXH() {
    }

    public bangXH(String name, int AC, int submit) {
        this.name = name;
        this.AC = AC;
        this.submit = submit;
    }

    public String getName() {
        return name;
    }

    public int getAC() {
        return AC;
    }

    public int getSubmit() {
        return submit;
    }

    public String toString() {
        return this.name + " " + this.AC + " " + this.submit;
    }
}

class SortBXH implements Comparator<bangXH> {
    public int compare(bangXH a, bangXH b) {
        if (a.getAC() != b.getAC()) {
            return b.getAC() - a.getAC();
        } else {
            if (a.getSubmit() != b.getSubmit()) {
                return a.getSubmit() - b.getSubmit();
            } else {
                return a.getName().compareTo(b.getName());
            }
        }
    }
}

public class J05042 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<bangXH> bxh = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            bxh.add(new bangXH(sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(bxh, new SortBXH());
        for (bangXH x : bxh) {
            System.out.println(x);
        }
    }
}



