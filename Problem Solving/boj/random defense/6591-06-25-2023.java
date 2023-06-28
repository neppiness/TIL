import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int n, k;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        while (n != 0) {
            BigInteger a = BigInteger.ONE;
            for (int i = n - k + 1; i <= n; i++)
                a = a.multiply(BigInteger.valueOf(i));

            BigInteger b = BigInteger.ONE;
            for (int i = 2; i <= k; i++)
                b = b.multiply(BigInteger.valueOf(i));

            sb.append(a.divide(b)).append('\n');
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
        }
        System.out.print(sb);
    }
}