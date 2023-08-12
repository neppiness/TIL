import java.io.*;
import java.util.*;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, s;
    static int[] a;

    static int gcd(int p, int q) {
        if (p == 0) return q;
        return gcd(q % p, p);
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        a = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());
            a[i] = x - s;
        }

        int ans = gcd(a[0], 0);
        for (int i = 1; i < n; i++)
            ans = gcd(ans, a[i]);
        System.out.print(Math.abs(ans));
    }
}