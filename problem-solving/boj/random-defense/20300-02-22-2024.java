import java.io.*;
import java.util.*;

public class Main {

    static long[] a;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        a = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(a);

        long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            int al = n - (n % 2);
            ans = Math.max(ans, a[i] + a[al - 1 - i]);
        }
        if (n % 2 == 1) {
            ans = Math.max(ans, a[n - 1]);
        }
        System.out.print(ans);
    }

}

