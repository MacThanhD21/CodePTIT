package OOP;





import java.util.*;


public class J04002_Submit {
    static class retangle{
        private double w, h;
        String color;

        public retangle() {
        }

        public retangle(double w, double h, String color) {
            this.w = w;
            this.h = h;
            this.color = color;
        }

        public double getW() {
            return w;
        }

        public void setW(double w) {
            this.w = w;
        }

        public double getH() {
            return h;
        }

        public void setH(double h) {
            this.h = h;
        }

        public String getColor() {
            return color;
        }

        public void setColor(String color) {
            this.color = color;
        }

        double findArea() {
            return this.w * this.h;
        }

        double findPerimeter() {
            return (this.w + this.h) * 2;
        }

        @Override
        public String toString() {
            String res = "";
            res += Character.toUpperCase(this.color.charAt(0));
            for (int i = 1; i < this.color.length(); i++) {
                res += Character.toLowerCase(this.color.charAt(i));
            }
            this.color = res;

            return (int) findPerimeter() + " " + (int) findArea() + " " + this.color;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double w = sc.nextDouble(), h = sc.nextDouble();
        String c = sc.next();
        if (w <= 0 || h <= 0) {
            System.out.println("INVALID");
        } else {
            retangle a = new retangle(w, h, c);
            System.out.println(a);
        }
    }
}

