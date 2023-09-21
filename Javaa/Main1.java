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
import java.util.Scanner;

public class Main1 {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // File nhị phân
        FileOutputStream out = new FileOutputStream("DATA.txt");
        for (int i = 0; i < 1000; i++) {
            out.write(i);
        }
        out.close();
    }
}
