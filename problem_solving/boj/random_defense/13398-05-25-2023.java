import java.io.*;
import java.util.*;


public class Main {

    final static int minusInf = -1_111_111_111;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n;
    static List<Integer> a = new ArrayList<>();
    static int[][] cache = new int[100_002][2];

    static int solve(int idx, int isSkipUsed) {
        if (idx == 0) {
            if (isSkipUsed == 1) return minusInf;
            else return a.get(0);
        }
        int ret = cache[idx][isSkipUsed];
        if (ret != minusInf) return ret;
        ret = 0;

        int cur = a.get(idx);
        if (isSkipUsed == 0) {
            ret = Math.max(solve(idx - 1, 0) + cur, cur);
        } else {
            ret = Math.max(solve(idx - 1, 0), solve(idx - 1, 1) + cur);
        }
        cache[idx][isSkipUsed] = ret;
        return ret;
    }

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        while (st.hasMoreElements())
            a.add(Integer.parseInt(st.nextToken()));

        for (int i = 0; i < n; i++)
            Arrays.fill(cache[i], minusInf);

        int ans = minusInf;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, solve(i, 0));
            ans = Math.max(ans, solve(i, 1));
        }
        System.out.print(ans);
    }
}