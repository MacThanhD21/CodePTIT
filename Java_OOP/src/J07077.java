import java.io.*;
import java.util.*;


public class J07077 {
    public static void main(String[] args) throws FileNotFoundException{
        Scanner sc = new Scanner(System.in);
        // Scanner sc = new Scanner(new File("BIEUTHUC.in"));

        int t = Integer.parseInt(sc.nextLine());
        while(t-- > 0){
            String s = sc.nextLine();
            Stack<Long> num = new Stack<>();
            Stack<Character> op = new Stack<>();
            for(int i = 0; i < s.length(); i++){
                char c = s.charAt(i);
                if(c == '(') op.push(c);
                else if(c == ')'){
                    while(op.peek() != '('){
                        long b = num.pop();
                        long a = num.pop();
                        char o = op.pop();
                        num.push(calc(a, b, o));
                    }
                    op.pop();
                }
                else if(c == '+' || c == '-' || c == '*' || c == '/'){
                    while(!op.isEmpty() && priority(op.peek()) >= priority(c)){
                        long b = num.pop();
                        long a = num.pop();
                        char o = op.pop();
                        num.push(calc(a, b, o));
                    }
                    op.push(c);
                }
                else{
                    long x = 0;
                    while(i < s.length() && Character.isDigit(s.charAt(i))){
                        x = x * 10 + s.charAt(i) - '0';
                        i++;
                    }
                    i--;
                    num.push(x);
                }
            }
            while(!op.isEmpty()){
                long b = num.pop();
                long a = num.pop();
                char o = op.pop();
                num.push(calc(a, b, o));
            }
            System.out.println(num.peek());
        }
    }
    
    public static int priority(char c){
        if(c == '+' || c == '-') return 1;
        if(c == '*' || c == '/') return 2;
        if(c == '^') return 3;
        return 0;
    }
    public static long calc(long a, long b, char c){
        if(c == '+') return a + b;
        else if(c == '-') return a - b;
        else if(c == '*') return a * b;
        else return a / b;
    }
}