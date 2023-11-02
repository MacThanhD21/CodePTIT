// import java.io.FileInputStream;
// import java.io.IOException;example.txt
// result.txt

// public class Main1 {
//     public static void main(String[] args) {
//         try {
//             FileInputStream fis = new FileInputStream("E:\\IT\\CODE_PTIT\\Javaa\\example.txt");
//             byte[] buffer = new byte[1024];
//             int bytesRead;

//             while ((bytesRead = fis.read(buffer)) != -1) {
//                 System.out.write(buffer, 0, bytesRead);
//             }

//             fis.close();
//         } catch (IOException e) {
//             e.printStackTrace();
//         }
//     }
// }

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main1 {
    public static void main(String[] args)  {
        // forEach method in java
        
        // 1. ArrayList
        List<String> myList = Arrays.asList("Cherry", "Apple", "Banana", "Orange");
        Collections.sort(myList);
        myList.forEach(item -> System.out.println(item));


        // 2. Set
        Set<Integer> mySet = new HashSet<>(Arrays.asList(1, 3, 2));
        mySet.forEach(number -> System.out.println(number));

        // 3. Map
        Map<String, Integer> myMap = new HashMap<>();
        myMap.put("One", 1);
        myMap.put("Two", 2);

        myMap.forEach((key, value) -> System.out.println(key + ": " + value));


        // 4. Stream

        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5);
        numbers.stream()
            .filter(n -> n % 2 == 0)
            .forEach(evenNumber -> System.out.println(evenNumber));

    }
}
