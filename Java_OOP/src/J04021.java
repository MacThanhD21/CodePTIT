


import java.util.*;

class IntSet {
    private int[] a;

    public IntSet(int[] a) {
        this.a = a;
    }
    
    public IntSet union(IntSet dif) {
        Set<Integer> se = new TreeSet<>();
        for(int x : a) {
            se.add(x);
        }
        for(int x : dif.a) {
            se.add(x);
        }
        
        return new IntSet(se.stream().mapToInt(Integer::intValue).toArray());
    }

    @Override
    public String toString()
    {
        String s = "";
        for (int i : a)
            s += Integer.toString(i) + " ";
        return s;
    }
}

public class J04021 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), a[] = new int[n], b[] = new int[m];
        for(int i = 0; i<n; i++) a[i] = sc.nextInt();
        for(int i = 0; i<m; i++) b[i] = sc.nextInt();
        IntSet s1 = new IntSet(a);
        IntSet s2 = new IntSet(b);
        IntSet s3 = s1.union(s2);
        System.out.println(s3);
    }
}