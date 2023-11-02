
import java.io.*;
import java.util.*;

class Pairrr<T, S> {
    
    private T first;
    private S second;

    public Pairrr(T first, S second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public S getSecond() {
        return second;
    }

    @Override
    public String toString() {
        return first + " " + second;
    }

    public boolean isPrime() {
        if ((Integer)first < 2 || (Integer)second < 2) {
            return false;
        }
        for (Integer i = 2; i <= Math.sqrt((Integer)first); i++) {
            if ((Integer)first % i == 0) {
                return false;
            }
        }
        for (Integer i = 2; i <= Math.sqrt((Integer)second); i++) {
            if ((Integer)second % i == 0) {
                return false;
            }
        }
        return true;
    }
}

public class Mainn {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DATA.in"));
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            boolean check = false;
            for(int i = 2; i <= 2*Math.sqrt(n); i++){
                Pairrrr<Integer, Integer> p = new Pairrrr<>(i, n-i);
                if(p.isPrime()){
                    System.out.println(p);
                    check = true;
                    break; 
                }
            }
            if(!check) System.out.println(-1);
        }
    }
}
