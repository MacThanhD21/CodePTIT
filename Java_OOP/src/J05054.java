import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class HocSinh implements Comparable<HocSinh> {
    private String id, name, type;
    private double diemTB;

    public HocSinh(int id, String name, double diemTB) {
        this.id = "HS" + String.format("%02d", id);
        this.name = name;
        this.diemTB = diemTB;
        if (this.diemTB < 5) {
            this.type = "Yeu";
        } else if (this.diemTB < 7) {
            this.type = "Trung Binh";
        } else if (this.diemTB < 9) {
            this.type = "Kha";
        } else {
            this.type = "Gioi";
        }
    }

    public String getId() {
        return this.id;
    }

    public double getDiemTB() {
        return this.diemTB;
    }

    @Override
    public int compareTo(HocSinh o) {
        if (this.diemTB < o.diemTB)
            return 1;
        return -1;
    }

    @Override
    public String toString() {
        return this.id + " " + this.name + " " + this.diemTB + " " + this.type;
    }
}

public class J05054 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<HocSinh> ds = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            ds.add(new HocSinh(i + 1, sc.nextLine(), Double.parseDouble(sc.nextLine())));
        }

        ArrayList<HocSinh> tmp = new ArrayList<>(ds);
        Collections.sort(tmp);

        HashMap<String, Integer> map = new HashMap<>();
        map.put(tmp.get(0).getId(), 1);
        for (int i = 1; i < tmp.size(); i++) {
            // Xử lý 1: Nếu Nó gặp thằng mà cùng hạng, thì lấy luôn giá trị value của key
            // trước đó vào key hiện tại
            if (tmp.get(i).getDiemTB() == tmp.get(i - 1).getDiemTB())
                map.put(tmp.get(i).getId(), map.get(tmp.get(i - 1).getId()));
            // Xử lý 2: Nếu như không cùng hạng với ai, thì có thể nhảy qua 1 hạng hiện tại
            // mà thằng vừa nãy đã bo qua, nhảy đến hạng tiếp theo, chính là i + 1.
            else
                map.put(tmp.get(i).getId(), i + 1);
        }
        for (HocSinh x : ds) {
            System.out.print(x + " " + map.get(x.getId()));
            System.out.println();
        }
    }
}