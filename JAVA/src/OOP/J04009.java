package OOP;

import java.util.*;
import java.io.*;

public class J04009 {
    
    static class Point{
        private double x, y;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
        
        
        public double getX()
        {
            return x;
        }

        public void setX(double x)
        {
            this.x = x;
        }

        public double getY()
        {
            return y;
        }

        public void setY(double y)
        {
            this.y = y;
        }

        public double getDist(Point A)
        {
            return Math.sqrt((this.x - A.x) * (this.x - A.x) + (this.y - A.y) * (this.y - A.y));
        }
    }
    
    static class Triangle{
        
        private Point A, B, C;

        public Triangle(Point A, Point B, Point C) {
            this.A = A;
            this.B = B;
            this.C = C;
        }

        
        @Override
        public String toString()
        {
            double AB, AC, BC;
            AB = this.A.getDist(this.B);
            AC = this.A.getDist(this.C);
            BC = this.B.getDist(this.C);
            
            if (AB + AC <= BC || AC + BC <= AB || AB + BC <= AC)
                return String.format("INVALID");
            double p = (AB + AC + BC) / 2.0;
            return String.format("%.2f", Math.sqrt(p * (p - AB) * (p - AC) * (p - BC)));
        }
    }
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0)
        {
            Point A = new Point(sc.nextDouble(),sc.nextDouble());
            Point B = new Point(sc.nextDouble(),sc.nextDouble());
            Point C = new Point(sc.nextDouble(),sc.nextDouble());
            Triangle siu = new Triangle(A, B, C);
            System.out.println(siu);
        }
    }
}