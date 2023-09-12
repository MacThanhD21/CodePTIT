package OOP;

import java.util.*;

class PhanSo
{
    private long tuSo;
    private long mauSo;

    public PhanSo(long tuSo, long mauSo)
    {
        this.tuSo = tuSo;
        this.mauSo = mauSo;
    }

    public long gcd(long a, long b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public void rutGon()
    {
        long GCD = gcd(this.tuSo, this.mauSo);
        this.tuSo /= GCD;
        this.mauSo /= GCD;
    }

    public PhanSo congPhanSo(PhanSo A)
    {
        long mauSo = this.mauSo * A.mauSo / gcd(this.mauSo, A.mauSo);
        long tuSo = (this.tuSo * (mauSo / this.mauSo)) + (A.tuSo * (mauSo / A.mauSo));
        PhanSo res = new PhanSo(tuSo, mauSo);
        res.rutGon();
        return res;
    }

    public PhanSo nhanPhanSo(PhanSo A)
    {
        PhanSo res = new PhanSo(this.tuSo * A.tuSo, this.mauSo * A.mauSo);
        res.rutGon();
        return res;
    }

    @Override
    public String toString()
    {
        return tuSo + "/" + mauSo;
    }
}



public class J04014
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n-- > 0)
        {
            PhanSo A = new PhanSo(sc.nextLong(), sc.nextLong());
            PhanSo B = new PhanSo(sc.nextLong(), sc.nextLong());
            PhanSo C = A.congPhanSo(B);
            C = C.nhanPhanSo(C);
            System.out.println(C + " " + A.nhanPhanSo(B.nhanPhanSo(C)));
        }
    }
}

