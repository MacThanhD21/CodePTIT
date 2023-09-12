import java.util.Comparator;

public class SortIncrease implements Comparator<Time>{

    @Override
    public int compare(Time o1, Time o2) {
        int res1 = Integer.parseInt(o1.getH() + o1.getM() + o1.getS()); 
        int res2 = Integer.parseInt(o2.getH() + o2.getM() + o2.getS()); 

        if(res1 < res2) return -1;
        else return 1;
    }
}
