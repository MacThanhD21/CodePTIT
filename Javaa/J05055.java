
import java.util.*;

class Athlete implements Comparable<Athlete> {
    private String id, name, DOB, st_time, en_time;

    public Athlete(int id, String name, String DOB, String st_time, String en_time) {
        this.id = "VDV" + String.format("%02d", id);
        this.name = name;
        this.DOB = DOB;
        this.st_time = st_time;
        this.en_time = en_time;
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

    public String getDOB() {
        return this.DOB;
    }

    public void setDOB(String DOB) {
        this.DOB = DOB;
    }

    public String getSt_time() {
        return this.st_time;
    }

    public void setSt_time(String st_time) {
        this.st_time = st_time;
    }

    public String getEn_time() {
        return this.en_time;
    }

    public void setEn_time(String en_time) {
        this.en_time = en_time;
    }

    public long getRealTime() {
        String[] data1 = this.st_time.split(":");

        long start = Long.parseLong(data1[0]) * 3600
                + Long.parseLong(data1[1]) * 60
                + Long.parseLong(data1[2]);

        String[] data2 = this.en_time.split(":");

        long end = Long.parseLong(data2[0]) * 3600
                + Long.parseLong(data2[1]) * 60
                + Long.parseLong(data2[2]);

        return end - start;
    }

    public long getPrio() {
        int Age = 2021 - Integer.parseInt(this.DOB.substring(6));

        if (Age < 18) {
            return 0;
        } else if (Age < 25) {
            return 1;
        } else if (Age < 32) {
            return 2;
        } else {
            return 3;
        }
    }

    public long getResult() {
        return this.getRealTime() - this.getPrio();
    }

    @Override
    public String toString() {
        return this.id
                + " " + this.name
                + " "
                + String.format("%02d:%02d:%02d", this.getRealTime() / 3600, (this.getRealTime() % 3600) / 60,
                        this.getRealTime() % 60)
                + " "
                + String.format("%02d:%02d:%02d", this.getPrio() / 3600, (this.getPrio() % 3600) / 60,
                        this.getPrio() % 60)
                + " "
                + String.format("%02d:%02d:%02d", this.getResult() / 3600, (this.getResult() % 3600) / 60,
                        this.getResult() % 60);
    }

    @Override
    public int compareTo(Athlete o) {
        return (int) (this.getResult() - o.getResult());
    }
}

public class J05055 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        ArrayList<Athlete> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            arr.add(new Athlete(i + 1, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        // Tạo một danh sách mới và sao chép nội dung từ danh sách ban đầu
        ArrayList<Athlete> newArr = new ArrayList<>(arr);

        Collections.sort(newArr);

        HashMap<String, Integer> map = new HashMap<>();

        map.put(newArr.get(0).getId(), 1);

        for (int i = 1; i < newArr.size(); i++) {
            // Xử lý 1: Nếu Nó gặp thằng mà cùng hạng, thì lấy luôn giá trị value của key
            // trước đó vào key hiện tại
            if (newArr.get(i).getResult() == newArr.get(i - 1).getResult())
                map.put(newArr.get(i).getId(), map.get(newArr.get(i - 1).getId()));
            // Xử lý 2: Nếu như không cùng hạng với ai, thì có thể nhảy qua 1 hạng hiện tại
            // mà thằng vừa nãy đã bo qua, nhảy đến hạng tiếp theo, chính là i + 1.
            else {
                map.put(newArr.get(i).getId(), i + 1);
            }
        }

        for (Athlete X : arr) {
            System.out.print(X + " " + map.get(X.getId()));
            System.out.println();
        }
    }
}