import java.util.*;

class Time implements Comparable<Time> {
    int hour, minute, second;

    public Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    @Override
    public int compareTo(Time other) {
        if (hour != other.hour) {
            return Integer.compare(hour, other.hour);
        }
        if (minute != other.minute) {
            return Integer.compare(minute, other.minute);
        }
        return Integer.compare(second, other.second);
    }

    @Override
    public String toString() {
        return String.format("%02d %02d %02d", hour, minute, second);
    }
}

public class J05003 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        ArrayList<Time> times = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            int hour = scanner.nextInt();
            int minute = scanner.nextInt();
            int second = scanner.nextInt();
            times.add(new Time(hour, minute, second));
        }

        Collections.sort(times);

        for (Time time : times) {
            System.out.println(time);
        }
    }
}