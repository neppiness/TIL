import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static String target;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {

        target = br.readLine();
        sb = new StringBuilder(br.readLine());
        while (sb.length() != target.length()) {
            if (sb.charAt(sb.length() - 1) == 'A') {

            } else {

            }
        }
    }
}