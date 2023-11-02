
import java.io.*;
import java.util.*;
    
class MonThi {
    private String id, name, Exam_forms;

    public MonThi(String id, String name, String Exam_forms) {
        this.id = id;
        this.name = name;
        this.Exam_forms = Exam_forms;
    }

    public String getId() {
        return this.id;
    }

    @Override
    public String toString() {
        return this.id + " "  + this.name + " " + this.Exam_forms;
    }
}
public class J07058 {
    
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("MONHOC.in"));
        
            int n = Integer.parseInt(sc.nextLine());
            
            ArrayList<MonThi> arr = new ArrayList<>();
            for(int i = 0; i < n; i++) {
                arr.add(new MonThi(sc.nextLine(), sc.nextLine(), sc.nextLine()));
            }

            Collections.sort(arr, new Comparator<MonThi>() {

                @Override
                public int compare(MonThi o1, MonThi o2) {
                    return o1.getId().compareTo(o2.getId());
                }
            });

            for(MonThi x : arr) {
                System.out.println(x);
            }
        } catch (FileNotFoundException e) {
            e.getStackTrace();
        }
    }
}