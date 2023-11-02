
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

class Student implements Comparable<Student>{
    private String id, name, phone_number;
    public String gr = "", Topic = "";
    public Student(String id, String name, String phone_number) {
        this.id = id;
        this.name = name;
        this.phone_number = phone_number;
    }


    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.phone_number + " " + this.gr + " " + this.Topic;
    }


    @Override
    public int compareTo(Student o) {
        return this.id.compareTo(o.id);
    }
}

class Task {
    private String Task_name;

    public Task(String Task_name) {
        this.Task_name = Task_name;
    }
}

class Group {
    private String id, gr_num;

    public Group(String id, String gr_num, ArrayList<Student> dsSV, HashMap<Integer, String> hm) {
        this.id = id;
        this.gr_num = gr_num;
        for(Student tmp : dsSV) {
            if(tmp.toString().contains(this.id)) {
                tmp.gr = this.gr_num;
                tmp.Topic = hm.get(Integer.parseInt(this.gr_num));
            }
        }
    }
}

public class J07027 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        // Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());
        
        ArrayList<Student> dsSV = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            String id = sc.nextLine();
            String name = sc.nextLine();
            String phone_number = sc.nextLine();
            dsSV.add(new Student(id, name, phone_number));
        }
        sc = new Scanner(new File("BAITAP.in"));
        int m = Integer.parseInt(sc.nextLine());
        ArrayList <Task> dsTasks = new ArrayList<>();
        int cnt = 1;
        HashMap<Integer, String> hm = new HashMap<>();
        for(int i = 0; i < m; i++) {
            String Task_name = sc.nextLine();
            dsTasks.add(new Task(Task_name));
            hm.put(cnt++, Task_name);
        }

        sc = new Scanner(new File("NHOM.in"));
        ArrayList <Group> dsGroups = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            String id = sc.next();
            String gr_num = sc.nextLine().substring(1);
            dsGroups.add(new Group(id, gr_num, dsSV, hm));
        }
        Collections.sort(dsSV);
        for(Student tmp : dsSV) {
            System.out.println(tmp);
        }
        sc.close();
    }
}
