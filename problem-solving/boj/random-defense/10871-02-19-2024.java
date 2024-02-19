import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String line = br.readLine();
        String[] splitLine = line.split(" ");
        int n = Integer.parseInt(splitLine[0]);
        int x = Integer.parseInt(splitLine[1]);

        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int y = Integer.parseInt(st.nextToken());
            if (y >= x) continue;
            sb.append(y).append(' ');
        }
        System.out.print(sb);
    }

}
