import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    public static void main(String args[]) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] s = new int[n + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++)
            s[i] = s[i -1] + Integer.parseInt(st.nextToken());

        int m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());
            sb.append(s[j] - s[i - 1]).append('\n');
        }
        System.out.println(sb);
    }
}