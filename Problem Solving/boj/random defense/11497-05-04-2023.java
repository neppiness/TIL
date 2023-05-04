import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static void solve() throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];

        int ans = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            a[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(a);

        int nxt = 2, cur = 0;
        while (nxt < n) {
            ans = Math.max(a[nxt] - a[cur], ans);
            cur = nxt;
            nxt += 2;
        }
        nxt--;
        if (nxt == n) nxt -= 2;

        while (nxt >= 1) {
            ans = Math.max(a[cur] - a[nxt], ans);
            cur = nxt;
            nxt -= 2;
        }
        sb.append(ans).append('\n');
    }

    
    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) solve();
        System.out.print(sb);
    }
}