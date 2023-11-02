import java.util.*;

class WordSet {
    private TreeSet<String> words;

    public WordSet(String input) {
        // notice################################################
        words = new TreeSet<>(Arrays.asList(input.toLowerCase().split("\\s+")));
    }

    public String union(WordSet other) {
        TreeSet<String> unionSet = new TreeSet<>(this.words);
        unionSet.addAll(other.words);
        return String.join(" ", unionSet);
    }

    public String intersection(WordSet other) {
        TreeSet<String> intersectSet = new TreeSet<>(this.words);
        intersectSet.retainAll(other.words);
        return String.join(" ", intersectSet);
    }
}

public class J04022 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        WordSet s1 = new WordSet(in.nextLine());
        WordSet s2 = new WordSet(in.nextLine());


        System.out.println(s1.union(s2));
        System.out.println(s1.intersection(s2));

    }
}
