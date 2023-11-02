

import java.util.*;


class List_of_internships {
    private int stt;
    private String id, name, clas, mail, busines;


    public List_of_internships(int stt, String id, String name, String clas, String mail, String busines) {
        this.stt = stt;
        this.id = id;
        this.name = name;
        this.clas = clas;
        this.mail = mail;
        this.busines = busines;
    }

    public String getId() {
        return this.id;
    }
    public String getName() {
        return this.name;
    }

    public String getBusines() {
        return this.busines;
    }

    @Override
    public String toString() {
        return this.stt + " " + this.id + " " + this.name + " " + this.clas + " " + this.mail + " " + this.busines;
    }
}

public class J05034 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<List_of_internships> arr = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            arr.add(new List_of_internships(i + 1, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }

        Collections.sort(arr, new Comparator<List_of_internships>() {

            @Override
            public int compare(List_of_internships o1, List_of_internships o2) {
                return o1.getId().compareTo(o2.getId());                
            }
        });
        
        int q = Integer.parseInt(sc.nextLine());

        while(q--> 0) {
            String res = sc.nextLine();
            for(List_of_internships x : arr) {
                if(x.getBusines().equals(res)) {
                    System.out.println(x);
                }
            }
        }
    }
}