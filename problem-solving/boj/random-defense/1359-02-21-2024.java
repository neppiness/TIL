import java.io.*;
import java.util.*;

public class Main {

    static int[][] comb = new int[10][10];

    static int calc(int n, int k) {
        if (n < k) {
            return 0;
        }
        if (comb[n][k] != -1) {
            return comb[n][k];
        }
        if (k == n || k == 0) {
            return comb[n][k] = 1;
        }
        return comb[n][k] = calc(n - 1, k) + calc(n - 1, k - 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        for (int i = 0; i < 10; i++) {
            Arrays.fill(comb[i], -1);
        }
        int de = calc(n, m);
        int nu = 0;
        for (int i = k; i <= m; i++) {
            nu += calc(m, i) * calc(n - m, m - i);
        }
        double ans = (double) nu / de;
        System.out.print(ans);
    }

}

