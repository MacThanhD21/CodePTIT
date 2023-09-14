
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class CopyFile {
    public static void main(String[] args) throws FileNotFoundException {
        // FileInputStream in = new FileInputStream("DATA.txt");

        // FileOutputStream out = new FileOutputStream("DATA_out.txt");

        // int x = 0;

        // while(true) {
        // x = in.read();
        // if (x == -1) break;
        // out.write(x);
        // }
        // out.close();
        BufferedInputStream in = new BufferedInputStream(new FileInputStream("DATA.txt"));

        BufferedOutputStream out = new BufferedOutputStream(new FileOutputStream("DATA_out.txt"));

        int x = 0;
        while (true) {
            x = in.read();
            if (x == -1)
                break;
            out.write(x);
        }
        out.close();
    }
}
