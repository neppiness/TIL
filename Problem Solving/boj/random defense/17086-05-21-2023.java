import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, m, ans;

    static int[] dx = new int[]{1, 0, -1, 0, 1, 1, -1, -1};
    static int[] dy = new int[]{0, 1, 0, -1, -1, 1, -1, 1};
    static boolean[][] b = new boolean[52][52];
    static int[][] dist = new int[52][52];

    static List<Coord> sharkCoord = new ArrayList<>();

    static class Coord {
        final int x, y;
        Coord(int x_, int y_) { this.x = x_; this.y = y_; }
    }

    static boolean oob(int x, int y) {
        return (x < 0 || x >= n || y < 0 || y >= m);
    }

    static void solve() {
        Queue<Coord> q = new ArrayDeque<>();
        for (Coord sc : sharkCoord) {
            dist[sc.x][sc.y] = 0;
            q.add(sc);
        }
        while (!q.isEmpty()) {
            Coord cur = q.poll();
            int cx = cur.x, cy = cur.y;
            for (int dir = 0; dir < 8; dir++) {
                int nx = cx + dx[dir]; int ny = cy + dy[dir];
                if (oob(nx, ny) || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[cx][cy] + 1;
                q.add(new Coord(nx, ny));
            }
        }
    }

    static void setup() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                b[i][j] = (Integer.parseInt(st.nextToken()) == 1);
                if (b[i][j]) sharkCoord.add(new Coord(i, j));
            }
        }
        for (int i = 0; i < n; i++)
            Arrays.fill(dist[i], -1);
    }

    static void printAns() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!b[i][j]) ans = Math.max(ans, dist[i][j]);

        System.out.print(ans);
    }

    public static void main(String[] args) throws IOException {
        setup();
        solve();
        printAns();
    }
}