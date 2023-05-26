import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n;
    static int[] a;
    static int[] position = new int[22];

    static Long fact(int x) {
        if (x == 1) return 1L;
        return fact(x - 1) * x;
    }

    static void solve1() {
        Long seq = Long.parseLong(st.nextToken());
        Long f = fact(n - 1);
        Long count = 0L;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= n; j++) {
                if (isUsed[j] != 0) continue;
                if (count + f > seq) {
                    count += f;
                    isUsed[j] = true;
                    break;
                }
            }
            f /= i;
        }
    }

    static void solve2() {
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int type = Integer.parseInt(st.nextToken());
        if (type == 1) solve1(); else solve2();
    }
}