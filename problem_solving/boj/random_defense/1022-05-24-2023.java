import java.io.*;
import java.util.*;

public class Main {

    final static int limit = 100_020_001;

    static BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int r1, r2, c1, c2;
    static int maxLength;
    static int b[][];
    static String ans[][];

    static int dx[] = new int[]{0, -1, 0, 1};
    static int dy[] = new int[]{1, 0, -1, 0};


    static void setup() throws IOException {
        st = new StringTokenizer(br.readLine());

        r1 = Integer.parseInt(st.nextToken());
        c1 = Integer.parseInt(st.nextToken());
        r2 = Integer.parseInt(st.nextToken());
        c2 = Integer.parseInt(st.nextToken());

        b = new int[r2 - r1 + 1][c2 - c1 + 1];
        ans = new String[r2 - r1 + 1][c2 - c1 + 1];
    }

    static boolean oob(int x, int y) {
        return (x < r1 || x > r2 || y < c1 || y > c2);
    }

    static void solve() {
        int no = 1, cnt = 0, dir = 0, len = 1;
        if (!oob(0, 0)) b[-r1][-c1] = 1; // 초기 세팅

        int cx = 0, cy = 0;
        while (true) {
            int dl = len;
            while (dl-- > 0) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (++no > limit) return;
                if (!oob(nx, ny)) b[nx - r1][ny - c1] = no;
                cx = nx; cy = ny;
            }
            dir = (dir + 1) % 4;
            if (++cnt == 2) { len++; cnt = 0; }
        }
    }

    static void preProcess() {
        for (int i = 0; i <= r2 - r1; i++)
            for (int j = 0; j <= c2 - c1; j++) {
                ans[i][j] = String.valueOf(b[i][j]);
                maxLength = Math.max(ans[i][j].length(), maxLength);
            }

        for (int i = 0; i <= r2 - r1; i++)
            for (int j = 0; j <= c2 - c1; j++) {
                int lengthDiff = maxLength - ans[i][j].length();
                while (lengthDiff-- > 0) sb.append(' ');
                ans[i][j] = sb.append(ans[i][j]).toString();
                sb.setLength(0);
            }
    }

    static void print() {
        for (int i = 0; i <= r2 - r1; i++) {
            for (int j = 0; j <= c2 - c1; j++)
                sb.append(ans[i][j]).append(' ');
            sb.append('\n');
        }
        System.out.print(sb);
    }

    public static void main(String[] args) throws IOException {
        setup();
        solve();
        preProcess();
        print();
    }
}