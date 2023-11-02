import java.util.Scanner;

public class J01018 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numTests = scanner.nextInt(); // Đọc số lượng test cases
        
        for (int i = 0; i < numTests; i++) {
            long n = scanner.nextLong(); // Đọc số nguyên dương N
            String result = checkProperties(n) ? "YES" : "NO";
            System.out.println(result);
        }
    }
    
    // Hàm kiểm tra tính chất yêu cầu cho số nguyên dương N
    public static boolean checkProperties(long n) {
        if (sumOfDigitsDivisibleBy10(n) && adjacentDigitsDistinctBy2(n)) {
            return true;
        }
        return false;
    }
    
    // Hàm kiểm tra tính chất: Tổng chữ số của N chia hết cho 10
    public static boolean sumOfDigitsDivisibleBy10(long n) {
        long sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum % 10 == 0;
    }
    
    // Hàm kiểm tra tính chất: Các chữ số cạnh nhau đều khác nhau đúng 2 đơn vị
    public static boolean adjacentDigitsDistinctBy2(long n) {
        long prevDigit = n % 10;
        n /= 10;
        
        while (n > 0) {
            long currentDigit = n % 10;
            int diff = (int) Math.abs(currentDigit - prevDigit);
            
            if (diff != 2) {
                return false;
            }
            
            prevDigit = currentDigit;
            n /= 10;
        }
        
        return true;
    }
}
