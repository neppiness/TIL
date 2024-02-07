import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[] a, cnt = new int[4];
    static int n;
    static int min = 0x7f7f7f7f, max = -0x7f7f7f7f;

    static void solve(int lv, int res) {
        if (lv == n) {
            min = Math.min(min, res);
            max = Math.max(max, res);
            return;
        }

        if (cnt[0] != 0) {
            cnt[0]--;
            solve(lv + 1, res + a[lv]);
            cnt[0]++;
        }
        if (cnt[1] != 0) {
            cnt[1]--;
            solve(lv + 1, res - a[lv]);
            cnt[1]++;
        }
        if (cnt[2] != 0) {
            cnt[2]--;
            solve(lv + 1, res * a[lv]);
            cnt[2]++;
        }
        if (cnt[3] != 0) {
            cnt[3]--;
            solve(lv + 1, res / a[lv]);
            cnt[3]++;
        }
    }

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        a = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            a[i] = Integer.parseInt(st.nextToken());
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++)
            cnt[i] = Integer.parseInt(st.nextToken());

        solve(1, a[0]);

        System.out.println(max);
        System.out.println(min);
    }
}