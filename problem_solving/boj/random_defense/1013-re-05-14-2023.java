import java.io.*;
import java.util.regex.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int n;
    static String input;
    static String pattern1 = "(01)+";
    static String pattern2 = "(100+1+)+";

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            input = br.readLine();
            Matcher matcher1 = Pattern.compile(pattern1).matcher(input);
            Matcher matcher2 = Pattern.compile(pattern2).matcher(input);

            while (matcher1.find()) {
                System.out.print("Start index: " + matcher1.start());
                System.out.print(" End index: " + matcher1.end());
                System.out.println(" Found: " + matcher1.group());
            }
        }
    }
}