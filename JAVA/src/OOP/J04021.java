package OOP;


import java.util.*;

import java.util.Set;
import java.util.TreeSet;

class IntSet
{
    private int[] arr;

    public IntSet(int[] arr)
    {
        this.arr = arr;
    }

    public IntSet union(IntSet A)
    {
        Set<Integer> mySet = new TreeSet<>();
        for (int i : arr)
            mySet.add(i);
        for (int i : A.arr)
            mySet.add(i);
        return new IntSet(mySet.stream().mapToInt(Integer::intValue).toArray());
    }

    @Override
    public String toString()
    {
        String s = "";
        for (int i : arr)
            s += Integer.toString(i) + " ";
        return s;
    }
}

public class J04021
{
    public static void main(String[] args)
    {
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
