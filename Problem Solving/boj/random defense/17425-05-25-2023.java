import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int n;

    static void solve(int n) {
        Long sum = 0L;
        int i = 1;
        for (; i*i <= n; i++)
            sum += (long)(n/i)*i;
        i--;
        for (; i > 1; i--) {
            int start = n / i;
            int end = n / (i - 1);
            sum += (i - 1) * (end * (end + 1) / 2 - (start) * (start + 1) / 2);
        }
        sb.append(sum).append('\n');
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) solve(Integer.parseInt(br.readLine()));
        System.out.print(sb);
    }
}