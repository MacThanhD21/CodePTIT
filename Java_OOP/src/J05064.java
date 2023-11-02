package Javaa;

import java.util.Scanner;

class Teacher {
    private String id, name, basic_Sal;

    public Teacher(int i, String name, String basic_Sal) {
        this.id = String.format("GV%02d", i);
        this.name = name;
        this.basic_Sal = basic_Sal;
    }

}

public class J05064 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        sc.close();
    }
}
