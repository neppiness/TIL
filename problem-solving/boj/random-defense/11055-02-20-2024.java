import java.io.*;
import java.util.*;

public class Main {

    static int[] a = new int[1002];
    static int[] sum = new int[1002];
    static int max = 0;

    static int solve(int x) {
        if (sum[x] != -1) {
            return sum[x];
        }
        sum[x] = a[x];
        for (int i = 0; i < x; i++) {
            if (a[i] >= a[x]) {
                continue;
            }
            sum[x] = Math.max(sum[x], a[x] + solve(i));
        }
        max = Math.max(max, sum[x]);
        return sum[x];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        Arrays.fill(sum, -1);
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < n; i++) {
            solve(i);
        }
        System.out.print(max);
    }

}


