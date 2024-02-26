import java.io.*;
import java.util.*;

public class Main {

    static int k, n;
    static int[] a;

    static boolean solve(long x) {
        int count = 0;
        for (int i = 0; i < k; i++) {
            count += a[i] / x;
        }
        return count >= n;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        a = new int[k];

        for (int i = 0; i < k; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        long start = 1L;
        long end = (1L << 31) - 1;
        while (start < end) {
            long mid = (start + end) / 2 + 1L;
            if (solve(mid)) {
                start = mid;
            } else {
                end = mid - 1L;
            }
        }
        System.out.print(start);
    }

}

