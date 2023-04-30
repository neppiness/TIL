import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        long b[] = new long[n];
        for (int i = 0; i < n; i++)
            b[i] = Long.parseLong(st.nextToken());

        while (m-- != 0) {
            Arrays.sort(b);
            long sum = b[0] + b[1];
            b[0] = sum; b[1] = sum;
        }

        long ans = 0;
        for (long x : b) ans += x;

        bw.write(String.valueOf(ans));
        bw.flush();
    }
}