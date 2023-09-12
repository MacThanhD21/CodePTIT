package OOP;

import java.util.*;

public class J04019 {

    static class Point {
        private double x, y;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public double getX() {
            return x;
        }

        public void setX(double x) {
            this.x = x;
        }

        public double getY() {
            return y;
        }

        public void setY(double y) {
            this.y = y;
        }

        public double getDist(Point A) {
            return Math.sqrt((this.x - A.x) * (this.x - A.x) + (this.y - A.y) * (this.y - A.y));
        }

        // Static method to create a Point from Scanner input
        public static Point nextPoint(Scanner sc) {
            double x = sc.nextDouble();
            double y = sc.nextDouble();
            return new Point(x, y);
        }
    }

    static class Triangle {

        private Point A, B, C;

        public Triangle(Point A, Point B, Point C) {
            this.A = A;
            this.B = B;
            this.C = C;
        }

        public boolean valid() {
            double AB, AC, BC;
            AB = this.A.getDist(this.B);
            AC = this.A.getDist(this.C);
            BC = this.B.getDist(this.C);

            return (AB + AC > BC) && (AC + BC > AB) && (AB + BC > AC);
        }

        public String getPerimeter() {
            double AB, AC, BC;
            AB = this.A.getDist(this.B);
            AC = this.A.getDist(this.C);
            BC = this.B.getDist(this.C);

            return String.format("%.3f", AB + AC + BC);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- >0){
            Triangle a = new Triangle(Point.nextPoint(sc), Point.nextPoint(sc), Point.nextPoint(sc));
            if(!a.valid()){
                System.out.println("INVALID");
            } else{
                System.out.println(a.getPerimeter());
            }
        }
    }
    public static void main950523(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            Triangle a = new Triangle(Point.nextPoint(sc), Point.nextPoint(sc), Point.nextPoint(sc));
            if (!a.valid()) {
                System.out.println("INVALID");
            } else {
                System.out.println(a.getPerimeter());
            }
        }
    }
}

