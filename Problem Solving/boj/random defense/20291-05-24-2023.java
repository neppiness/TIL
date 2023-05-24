import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int n;
    static StringBuilder sb = new StringBuilder();
    static TreeMap<String, Integer> extensions = new TreeMap<>();

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String fileName = br.readLine();
            int dotIndex = fileName.indexOf('.');
            String extension = fileName.substring(dotIndex + 1);
            Integer count = extensions.get(extension);
            if (count == null) count = 0;
            extensions.put(extension, count + 1);
        }

        extensions.forEach((key, value) -> {
            sb.append(key).append(' ').append(value).append('\n');
        });
        System.out.print(sb);
    }
}