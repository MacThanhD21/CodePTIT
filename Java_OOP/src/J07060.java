
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Exam_Sub {
    private String id_Sub, name_Sub, exam_Type;

    public Exam_Sub(String id_Sub, String name_Sub, String exam_Type) {
        this.id_Sub = id_Sub;
        this.name_Sub = name_Sub;
        this.exam_Type = exam_Type;
    }

    public String getId_Sub() {
        return this.id_Sub;
    }
    public String getName_Sub() {
        return this.name_Sub;
    }
    public String getExam_Type() {
        return this.exam_Type;
    }
}

class Exam_Shift {
    private String id_Shift, exam_Date, exam_Hour, id_Room;

    public Exam_Shift(int id_Shift, String exam_Date, String exam_Hour, String id_Room) {
        this.id_Shift = "C" + String.format("%03d", (id_Shift));
        this.exam_Date = exam_Date;
        this.exam_Hour = exam_Hour;
        this.id_Room = id_Room;
    }

    public String getId_Shift() {
        return this.id_Shift;
    }
    public String getExam_Date() {
        return this.exam_Date;
    }
    public String getExam_Hour() {
        return this.exam_Hour;
    }
    public String getId_Room() {
        return this.id_Room;
    }
}

class Exam_Time implements Comparable<Exam_Time> {
    private String id_Shift, id_Sub, id_Gr, num_Student;
    private Exam_Sub exam_Sub;
    private Exam_Shift exam_Shift;

    public Exam_Time(String id_Shift, String id_Sub, String id_Gr, String num_Student, ArrayList<Exam_Sub> arr_Sub,
            ArrayList<Exam_Shift> arr_Shift) {
        this.id_Shift = id_Shift;
        this.id_Sub = id_Sub;
        this.id_Gr = id_Gr;
        this.num_Student = num_Student;

        for (Exam_Sub i : arr_Sub) {
            if (i.getId_Sub().equals(id_Sub)) {
                this.exam_Sub = i;
                break;
            }
        }
        for (Exam_Shift i : arr_Shift) {
            if (i.getId_Shift().equals(id_Shift)) {
                this.exam_Shift = i;
                break;
            }
        }
    }

    @Override
    public String toString() {
        return this.exam_Shift.getExam_Date() + " " + this.exam_Shift.getExam_Hour() + " "
                + this.exam_Shift.getId_Room() + " " + this.exam_Sub.getName_Sub() + " " + this.id_Gr + " "
                + this.num_Student;
    }

    @Override
    public int compareTo(Exam_Time o) {
        // TODO Auto-generated method stub
        if (this.exam_Shift.getExam_Date().equals(o.exam_Shift.getExam_Date())) {
            if (this.exam_Shift.getExam_Hour().equals(o.exam_Shift.getExam_Hour())) {
                return this.exam_Shift.getId_Shift().compareTo(o.exam_Shift.getId_Shift());
            } else {
                return this.exam_Shift.getExam_Hour().compareTo(o.exam_Shift.getExam_Hour());
            }
        } else {
            return this.exam_Shift.getExam_Date().compareTo(o.exam_Shift.getExam_Date());
        }
    }
}

public class J07060 {
    public static void main(String[] args) throws FileNotFoundException {
        // Scanner sc = new Scanner(System.in);
        Scanner sc = new Scanner(new File("MONTHI.in"));

        int n = Integer.parseInt(sc.nextLine());

        ArrayList<Exam_Sub> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String id_Sub = sc.nextLine();
            String name_Sub = sc.nextLine();
            String exam_Type = sc.nextLine();
            arr.add(new Exam_Sub(id_Sub, name_Sub, exam_Type));
        }
        sc = new Scanner(new File("CATHI.in"));
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Exam_Shift> arr1 = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String exam_Date = sc.nextLine();
            String exam_Hour = sc.nextLine();
            String id_Room = sc.nextLine();
            arr1.add(new Exam_Shift(i + 1, exam_Date, exam_Hour, id_Room));
        }
        sc = new Scanner(new File("LICHTHI.in"));
        ArrayList<Exam_Time> arr2 = new ArrayList<>();
        int k = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < k; i++) {
            // String s = sc.nextLine();
            // String[] a = s.split("\\s+");
            String id_Shift = sc.next();
            String id_Sub = sc.next();
            String id_Gr = sc.next();
            String num_Student = sc.next();
            arr2.add(new Exam_Time(id_Shift, id_Sub, id_Gr, num_Student, arr, arr1));
        }
        Collections.sort(arr2);
        for (Exam_Time i : arr2) {
            System.out.println(i);
        }
    }
}
