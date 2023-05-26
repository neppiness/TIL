import java.io.*;
import java.util.*;


public class Main {

    final static int mod = 1_000_000_007;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, m;
    static int[][] b = new int[1000][1000];

    static int[] dx = new int[]{0, -1, -1};
    static int[] dy = new int[]{-1, 0, -1};

    static int solve(int cx, int cy) {
        if (cx == 0 && cy == 0) return 1;
        if (b[cx][cy] != 0) return b[cx][cy];

        int ret = 0;
        for (int dir = 0; dir < 3; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || ny < 0) continue;
            ret += solve(nx, ny);
            if (ret > mod) ret -= mod;
        }
        b[cx][cy] = ret;
        return ret;
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        System.out.print(solve(n - 1, m - 1));
    }
}