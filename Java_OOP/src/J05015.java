import java.util.*;

class Bicycle {
    private String id, name, unit, target_Time;

    public Bicycle(String name, String unit, String target_Time) {
        this.name = name;
        this.unit = unit;
        this.target_Time = target_Time;
    }

    public String getId() {
        String[] arr1 = this.unit.split("\\s+");
        String[] arr2 = this.name.split("\\s+");
        String res = "";
        for (String x : arr1) {
            res += x.charAt(0);
        }

        for (String x : arr2) {
            res += x.charAt(0);
        }

        return res;
    }

    public String getTargetTime() {
        return this.target_Time;
    }

    public long getVelocity() {
        String time = this.target_Time;
        int idx = time.indexOf(":");

        int h = Integer.parseInt(time.substring(0, idx));

        int m = Integer.parseInt(time.substring(idx + 1));

        double t = (double) (h - 6) + (double) (m) / 60;

        long v = (int) Math.round(120 / t);

        return v;
    }

    @Override
    public String toString() {
        this.id = getId();
        return this.id + " " + this.name + " " + this.unit + " " + this.getVelocity() + " Km/h";
    }
}

public class J05015 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Bicycle> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            arr.add(new Bicycle(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }

        Collections.sort(arr, new Comparator<Bicycle>() {
            @Override
            public int compare(Bicycle o1, Bicycle o2) {
                return o1.getTargetTime().compareTo(o2.getTargetTime());
            }
        });

        for (Bicycle x : arr) {
            System.out.println(x);
        }
    }
}