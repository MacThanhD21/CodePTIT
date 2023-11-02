public class Main2 {
    public static void main(String[] args) {
        int year1 = 2012;
        int month1 = 2;
        int day1 = 5;

        int year2 = 2012;
        int month2 = 3;
        int day2 = 7;

        long daysBetween = calculateDaysBetween(year1, month1, day1, year2, month2, day2);

        System.out.println("Khoảng cách giữa hai ngày là " + daysBetween + " ngày.");
    }

    public static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    public static long calculateDaysBetween(int year1, int month1, int day1, int year2, int month2, int day2) {
        int[] daysInMonth = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        long days = 0;

        for (int year = year1; year <= year2; year++) {
            int startMonth = (year == year1) ? month1 : 1;
            int endMonth = (year == year2) ? month2 : 12;
            int maxDay = isLeapYear(year) ? 29 : 28;

            for (int month = startMonth; month <= endMonth; month++) {
                int maxDayOfMonth = (month == 2) ? maxDay : daysInMonth[month];
                int startDay = (year == year1 && month == month1) ? day1 : 1;
                int endDay = (year == year2 && month == month2) ? day2 : maxDayOfMonth;

                for (int day = startDay; day <= endDay; day++) {
                    days++;
                }
            }
        }

        return days; // Subtract 1 because we start from day1, not day0.
    }
}
