import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int n, m;
    static boolean[][] vis;
    static char[][] b;

    static int[] dx = new int[]{1, 0, -1, 0};
    static int[] dy = new int[]{0, 1, 0, -1};

    static boolean oob(int x, int y) {
        return (x >= n || x < 0 || y >= m || y < 0);
    }

    static class Coord {
        public int x, y;
        Coord(int x_, int y_) { this.x = x_; this.y = y_; }
    }

    static int solve(int x, int y, char code) {
        Queue<Coord> q = new ArrayDeque<>();
        int cnt = 1; vis[x][y] = true;
        q.add(new Coord(x, y));
        while (!q.isEmpty()) {
            Coord co = q.poll();
            int cx = co.x; int cy = co.y;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (oob(nx, ny) || vis[nx][ny]) continue;
                if (b[nx][ny] != code) continue;
                cnt++; vis[nx][ny] = true;
                q.add(new Coord(nx, ny));
            }
        }
        return cnt * cnt;
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        vis = new boolean[n][m];
        b = new char[n][m];

        for (int i = 0; i < n; i++)
            b[i] = br.readLine().toCharArray();

        int wtot = 0, btot = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (vis[i][j]) continue;
                if (b[i][j] == 'W') wtot += solve(i, j, b[i][j]);
                else btot += solve(i, j, b[i][j]);
            }

        sb.append(wtot).append(' ').append(btot);
        System.out.print(sb);
    }
}