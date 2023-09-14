import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;
import java.util.Map;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.*;

public class Main1 {

    public static void main(String[] args) {
        double number = 1266.5; // Số thập phân bạn muốn làm tròn
        long roundedNumber = Math.round(number / 10.0) * 10;
        System.out.println(roundedNumber); // Kết quả: 1260

    }
}