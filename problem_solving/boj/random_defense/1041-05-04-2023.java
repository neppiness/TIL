import java.io.*;
import java.util.*;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final long INF = 0x7f7f7f7f;
    static long[] min = new long[]{INF, INF, INF};
    static int[] b = new int[6];

    static int[][] comb1 = new int[][]{
            {0}, {1}, {2}, {3}, {4}, {5}
    };

    static int[][] comb2 = new int[][]{
            {0, 3}, {1, 3}, {4, 3}, {5, 3},
            {4, 2}, {0, 2}, {1, 2}, {5, 2},
            {0, 4}, {0, 1}, {1, 5}, {5, 4}
    };

    static int[][] comb3 = new int[][]{
            {0, 1, 2}, {0, 1, 3},
            {1, 5, 2}, {1, 5, 3},
            {4, 5, 2}, {4, 5, 3},
            {0, 4, 2}, {0, 4, 3}
    };

    static void calc(int[][] comb, int minidx) {
        for (int i = 0; i < comb.length; i++) {
            int sum = 0;
            for (int j = 0; j < comb[i].length; j++)
                sum += b[comb[i][j]];
            min[minidx] = Math.min(min[minidx], sum);
        }
    }

    public static void main(String[] args) throws IOException {

        long n = Long.parseLong(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 6; i++)
            b[i] = Integer.parseInt(st.nextToken());

        if (n == 1) {
            int sum = 0, max = 0;
            for (int i = 0; i < 6; i++) {
                sum += b[i];
                max = Math.max(max, b[i]);
            }
            System.out.print(sum - max);
            return;
        }

        calc(comb1, 0); calc(comb2, 1); calc(comb3, 2);
        long ans = 0L;
        ans += min[2] * 4;
        ans += min[1] * 4 * (2*n - 3);
        ans += min[0] * (n - 2) * (5*n - 6);
        System.out.print(ans);
    }
}