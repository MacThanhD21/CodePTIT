

public class Time {
    private String h, m, s;

    public Time(String h, String m, String s) {
        this.h = h;
        this.m = m;
        this.s = s;
    }

    public String getH() {
        return this.h;
    }

    public String getM() {
        return this.m;
    }

    public String getS() {
        return this.s;
    }

    @Override
    public String toString() {
        return this.h + " " + this.m + " " + this.s;
    }
}
