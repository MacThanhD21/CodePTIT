import java.util.*;
        
class NhanVien {
    private String id, name;

    public NhanVien(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() {
        return this.id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getPosition() {
        String res = this.id.substring(0, 2);
        return res;
    }

    public String getSoHieu() {
        return this.id.substring(4);
    }

    public String getBacLuong() {
        return this.id.substring(2, 4);
    }

    @Override
    public String toString() {
        return this.name + " " + this.getPosition() + " " + this.getSoHieu() + " " + this.getBacLuong();
    } 
}

public class J05065 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<NhanVien> arr = new ArrayList<>();

        int cnt_GD = 0, cnt_TP = 0, cnt_PP = 0;

        for(int i = 0; i < n; i++) {
            NhanVien x = new NhanVien(sc.next(), sc.nextLine());

            if(x.getPosition().equals("GD")) {
                cnt_GD++;
                if(cnt_GD > 1) {
                    String tmp = "NV" + x.getBacLuong() + x.getSoHieu();
                    x.setId(tmp); 
                    // System.out.println(x.getId());
                }
                arr.add(x);
            }
            else if(x.getPosition().equals("TP")) {
                cnt_TP++;
                if(cnt_TP > 3) {
                    String tmp = "NV" + x.getBacLuong() + x.getSoHieu();
                    x.setId(tmp);
                    // System.out.println(x.getId());
                }
                arr.add(x);
            }
            else if(x.getPosition().equals("PP")) {
                cnt_PP++;
                if(cnt_PP > 3) {
                    String tmp = "NV" + x.getBacLuong() + x.getSoHieu();
                    x.setId(tmp);
                    // System.out.println(x.getId());
                }
                arr.add(x);
            }
            else arr.add(x);
        }

        Collections.sort(arr, new Comparator<NhanVien>() {

            @Override
            public int compare(NhanVien o1, NhanVien o2) {
                if(o1.getBacLuong().equals(o2.getBacLuong())) {
                    int a = Integer.parseInt(o1.getSoHieu());
                    int b = Integer.parseInt(o2.getSoHieu());
                    return a - b;
                }                
                else {
                    return (int)(Integer.parseInt(o2.getBacLuong()) - Integer.parseInt(o1.getBacLuong()));
                }
            }
        });

        int q = Integer.parseInt(sc.nextLine());

        while(q-- > 0) {
            String s = sc.nextLine();
            for(NhanVien x : arr) {
                if(x.getPosition().equals(s)) {
                    System.out.println(x);
                }
            }
            System.out.println();
        }
    }
}