
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Subject {
    private String id, name, credits;

    public Subject(String id, String name, String credits) {
        this.id = id;
        this.name = name;
        this.credits = credits;
    }

    public String getId() {
        return this.id;
    }
    public String getName() {
        return this.name;
    }
    public String getCredits() {
        return this.credits;
    }

    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.credits;
    }
}

class SessionClass implements Comparable<SessionClass>{
    private String id_Group, id_Sub, TeachingDates, Study_Crew, name_Pro, id_Room;
    private Subject sub;

    public SessionClass(int id_Group, String id_Sub, String TeachingDates, String Study_Crew, String name_Pro, String id_Room, ArrayList<Subject> dsSub) {
        this.id_Group = "HP" + String.format("%03d", id_Group);
        this.id_Sub = id_Sub;
        this.TeachingDates = TeachingDates;
        this.Study_Crew = Study_Crew;
        this.name_Pro = name_Pro;
        this.id_Room = id_Room;
        for(Subject x : dsSub) {
            if(this.id_Sub.equals(x.getId())) {
                this.sub = x;
                break;
            }
        }
    }
    public String getNamePro() {
        return this.name_Pro;
    }
    @Override
    public int compareTo(SessionClass o) {
        if(this.TeachingDates != o.TeachingDates) {
            if(this.Study_Crew != o.Study_Crew) {
                return this.TeachingDates.compareTo(o.TeachingDates);
            }
            return this.Study_Crew.compareTo(o.Study_Crew);
        }
        return this.name_Pro.compareTo(o.name_Pro);
    }

    @Override
    public String toString() {
        return this.id_Group 
        + " " + this.sub.getName() 
        + " " + this.TeachingDates 
        + " " + this.Study_Crew 
        + " " + this.id_Room;
    }
}
public class J07075 {
    public static void main(String[] args) throws FileNotFoundException{
        // Scanner sc = new Scanner(System.in);
        Scanner sc = new Scanner(new File("MONHOC.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList <Subject> dsSub = new ArrayList<>();

        while(n-->0) {
            dsSub.add(new Subject(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        // for(Subject x : dsSub) {
        //     System.out.println(x);
        // }

        sc = new Scanner(new File("LICHGD.in"));
        n = Integer.parseInt(sc.nextLine());
        ArrayList <SessionClass> dsPro = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            dsPro.add(new SessionClass(i + 1, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), dsSub));
        }
        Collections.sort(dsPro);

        String name_Pro = sc.nextLine();

        System.out.println("LICH GIANG DAY GIANG VIEN " + name_Pro + ":");

        for(SessionClass x : dsPro) {
            if(x.getNamePro().equals(name_Pro)) {
                System.out.println(x);
            }
        }
    }
}
