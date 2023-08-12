import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int[][] b, pop;
    static int n, ans = 0x7f7f7f7f;
    static int x, y, d1, d2;

    static int dx[] = new int[]{1, 0, -1, 0};
    static int dy[] = new int[]{0, 1, 0, -1};

    static class CoordAndNo {
        public int x, y, no;
        CoordAndNo(int x_, int y_, int no_) {
            this.x = x_; this.y = y_; this.no = no_;
        }
    }

    static void setBorderLines() {
        b = new int[n + 2][n + 2];

        b[x][y] = 5; b[x + d1][y - d1] = 5;
        b[x + d2][y + d2] = 5;
        b[x + d1 + d2][y - d1 + d2] = 5;

        int cx = x, cy = y;
        while(cx < x + d1) b[++cx][--cy] = 5; // 1. (x, y) -> (x+d1, y-d1)
        while(cx < x + d1 + d2) b[++cx][++cy] = 5; // 3. (x+d1, y-d1) -> (x+d1+d2, y-d1+d2)
        while(cx > x + d2) b[--cx][++cy] = 5; // 4. (x+d1+d2, y-d1+d2) -> (x+d2, y+d2)
        while(cx > x) b[--cx][--cy] = 5; // 2. (x+d2, y+d2) -> (x, y)
    }

    static boolean oob(int cx, int cy, int code) {
        if (code == 1) {
            return (cx < 1 || cx >= x + d1 || cy < 1 || cy > y);
        } else if (code == 2) {
            return (cx < 1 || cx > x + d2 || cy <= y || cy > n);
        } else if (code == 3) {
            return (cx < x + d1 || cx > n || cy < 1 || cy >= y - d1 + d2);
        }
        return (cx <= x + d2 || cx > n || cy < y - d1 + d2 || cy > n);
    }

    static void setDistriction() {
        Queue<CoordAndNo> q = new ArrayDeque<>();
        b[1][1] = 1; b[1][n] = 2; b[n][1] = 3; b[n][n] = 4;
        q.add(new CoordAndNo(1, 1, 1));
        q.add(new CoordAndNo(1, n, 2));
        q.add(new CoordAndNo(n, 1, 3));
        q.add(new CoordAndNo(n, n, 4));

        while(!q.isEmpty()) {
            CoordAndNo coordAndNo = q.poll();
            int cx = coordAndNo.x;
            int cy = coordAndNo.y;
            int code = coordAndNo.no;

            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (oob(nx, ny, code) || b[nx][ny] != 0) continue;
                b[nx][ny] = code;
                q.add(new CoordAndNo(nx, ny, code));
            }
        }
    }

    static void calculateAndUpdateAnswer() {
        int[] totpop = new int[6];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (b[i][j] == 0) b[i][j] = 5;
                totpop[b[i][j]] += pop[i][j];
            }
        int mx = 0, mn = 0x7f7f7f7f;
        for (int i = 1; i <= 5; i++) {
            mx = Math.max(totpop[i], mx);
            mn = Math.min(totpop[i], mn);
        }
        ans = Math.min(mx - mn, ans);
    }

    static boolean isValid() {
        return (1 <= y - d1 && y + d2 <= n && x + d1 + d2 <= n);
    }

    static void solve() {
        for(d1 = 1; d1 <= n; d1++)
            for(d2 = 1; d2 <= n; d2++)
                if(isValid()) {
                    setBorderLines();
                    setDistriction();
                    calculateAndUpdateAnswer();
                }
    }

    public static void main(String args[]) throws IOException {
        n = Integer.parseInt(br.readLine());
        pop = new int[n + 2][n + 2];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++)
                pop[i][j] = Integer.parseInt(st.nextToken());
        }

        for (x = 1; x <= n; x++)
            for (y = 1; y <= n; y++)
                solve();

        System.out.print(sb.append(ans));
    }
}