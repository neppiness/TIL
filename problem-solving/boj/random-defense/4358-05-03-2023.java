import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static TreeMap<String, Integer> tm = new TreeMap<>();

    public static void main(String[] args) throws IOException {
        int cnt = 0;

        String name = "";
        while ((name = br.readLine()) != null) {
            cnt++;
            if (tm.get(name) == null) tm.put(name, 1);
            else tm.put(name, tm.get(name) + 1);
        }

        for (Map.Entry<String, Integer> entry: tm.entrySet()) {
            double percent = (double)entry.getValue() * 100 / cnt;
            sb.append(entry.getKey()).append(' ');
            sb.append(String.format("%.4f", percent)).append('\n');
        }
        System.out.print(sb);
    }
}