import java.io.*;
import java.util.*;

public class Main {

    static int compareTo(String a, String b) {
        if (a.length() == b.length()) {
            return a.compareTo(b);
        }
        return a.length() - b.length();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Set<String> wordSet = new HashSet<>();
        for (int i = 0; i < n; i++) {
            wordSet.add(br.readLine());
        }
        ArrayList<String> words = new ArrayList<>(wordSet);
        words.sort(Main::compareTo);
        StringBuilder sb = new StringBuilder();
        for (String word : words) {
            sb.append(word).append('\n');
        }
        System.out.print(sb);
    }

}

