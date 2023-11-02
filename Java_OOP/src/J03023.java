import java.util.*;

public class J03023 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numTests = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        for (int i = 0; i < numTests; i++) {
            String romanNumeral = scanner.nextLine();
            int decimalValue = convertToDecimal(romanNumeral);
            System.out.println(decimalValue);
        }
    }
    
    public static int convertToDecimal(String romanNumeral) {
        TreeMap<Character, Integer> romanValues = new TreeMap<>();
        romanValues.put('I', 1);
        romanValues.put('V', 5);
        romanValues.put('X', 10);
        romanValues.put('L', 50);
        romanValues.put('C', 100);
        romanValues.put('D', 500);
        romanValues.put('M', 1000);
        
        int result = 0;
        int prevValue = 0;
        
        for (int i = 0; i < romanNumeral.length(); i++) {
            char currentChar = romanNumeral.charAt(i);
            int currentValue = romanValues.get(currentChar);
            
            if (currentValue > prevValue) {
                result += currentValue - 2 * prevValue; // Correct for previous addition
            } else {
                result += currentValue;
            }
            
            prevValue = currentValue;
        }
        
        return result;
    }
}
