package javaa;



import java.util.*;

public class J05011 {
    static class GameThu{
        String id, name, st, en;

        public GameThu(String id, String name, String st, String en) {
            this.id = id;
            this.name = name;
            this.st = st;
            this.en = en;
        }

        public String getId() {
            return id;
        }

        public void setId(String id) {
            this.id = id;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getSt() {
            return st;
        }

        public void setSt(String st) {
            this.st = st;
        }

        public String getEn() {
            return en;
        }

        public void setEn(String en) {
            this.en = en;
        }
        
        public double getTime(){
            int h = (int) (Double.parseDouble(this.en.substring(0, 2)) - Double.parseDouble(this.st.substring(0, 2)));
            int m = (int) ((Double.parseDouble(this.en.substring(3)) - Double.parseDouble(this.st.substring(3))) / 60);
            
            return h + m;
        }

        @Override
        public String toString() {
            String Time = this.getTime() + "";
            String h = Time.substring(0, 1);
            int m = Integer.parseInt(Time.substring(2)) * 60;
            
            return this.id + " " + this.name + " " + h + "gio " + m + " phut";
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        
        sc.nextLine();
        
        ArrayList<GameThu> arr = new ArrayList<>();
        
        for(int i = 0; i < n; i++){
            arr.add(new GameThu(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        
        Collections.sort(arr, new Comparator<GameThu> () {
            @Override
            public int compare(GameThu o1, GameThu o2) {
                return (int) (o2.getTime() - o1.getTime());
            }
        });
        
        for(GameThu x : arr){
            System.out.println(x);
        }
    }
}
