
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class JKT013 {
    private static void Process(int n) {
        Queue<String> q = new LinkedList<>();
        Stack<String> stk = new Stack<>();
        q.add("6");
        q.add("8");
        while (true) {
            String tmp = q.poll();
            if (tmp.length() > n)
                break;
            stk.add(tmp);
            q.add(tmp + "6");
            q.add(tmp + "8");
        }
        System.out.println(stk.size());
        while (!stk.isEmpty()) {
            System.out.print(stk.peek() + " ");
            stk.pop();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            Process(sc.nextInt());
        }
    }
}
