package OOP;

import java.util.Scanner;

 class Point {
    private double x, y;

    public Point() {
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    double distance(Point secondPoint){
        return Math.sqrt(Math.pow(secondPoint.x - this.x, 2) + Math.pow(secondPoint.y - this.y, 2));
    }

    double distance(Point p1, Point p2){
        return Math.sqrt(Math.pow(p2.x - p1.x, 2) + Math.pow(p2.y - p1.y, 2));
    }

    @Override
    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}

public class J04008 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            Point p1 = new Point(sc.nextDouble(), sc.nextDouble());
            Point p2 = new Point(sc.nextDouble(), sc.nextDouble());
            Point p3 = new Point(sc.nextDouble(), sc.nextDouble());
            double a = p1.distance(p2), b = p1.distance(p3), c = p2.distance(p3);
            if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) {
                System.out.printf("%.3f\n", a + b + c);
            } else {
                System.out.println("INVALID");
            }
        }
    }
}