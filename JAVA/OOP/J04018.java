package OOP;



import java.util.Scanner;

public class J04018 {
    private int thuc,ao;

    public J04018(){
    }
    public J04018(int thuc, int ao) {
        this.thuc = thuc;
        this.ao = ao;
    }
    
    J04018 add(J04018 p){
        J04018 n = new J04018();
        n.thuc = this.thuc+p.thuc;
        n.ao = this.ao+p.ao;
        return n;
    }
    J04018 mul(J04018 p){
        J04018 n = new J04018();
        n.thuc = this.thuc*p.thuc-this.ao*p.ao;
        n.ao = this.ao*p.thuc+this.thuc*p.ao;
        return n;
    }
    
    @Override
    public String toString(){
        String s = "";
        s += String.valueOf(this.thuc);
        if(this.ao<0) s += " - ";
        else s += " + ";
        s += String.valueOf(Math.abs(this.ao)) + 'i';
        return s;
    }
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            J04018 a = new J04018(sc.nextInt(),sc.nextInt());
            J04018 b = new J04018(sc.nextInt(),sc.nextInt());
            J04018 e = a.add(b);
            System.out.print(e.mul(a));
            System.out.print(", ");
            System.out.println(e.mul(e));
        }
    }
}
