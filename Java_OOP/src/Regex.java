
public class Regex {
    public static void main(String[] args) {
        String text = "HelloWorld! This        is an       example         text.";

        // Split the text using \W as the delimiter
        String[] words = text.split("(\\W\\s)*");

        for (String word : words) {
            System.out.println(word);
        }
    }
}
