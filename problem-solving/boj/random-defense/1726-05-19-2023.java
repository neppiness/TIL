import java.io.*;
import java.util.*;
import static java.lang.Integer.parseInt;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static boolean[][] isBlocked = new boolean[102][102];
    static int[][][] dist = new int[102][102][5]; // x, y, dir

    static int n, m;
    static int dx[] = new int[]{0, 0, 1, -1};
    static int dy[] = new int[]{1, -1, 0, 0};

    static class Status {
        int x, y, dir;
        Status(int x_, int y_, int dir_) {
            this.x = x_; this.y = y_; this.dir = dir_;
        }
    }

    static boolean oob(int x, int y) {
        return (x >= m || x < 0 || y >= n || y < 0);
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        m = parseInt(st.nextToken());
        n = parseInt(st.nextToken());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++)
                isBlocked[i][j] = (parseInt(st.nextToken()) == 1);
        }

        st = new StringTokenizer(br.readLine());
        Status start = new Status(
                parseInt(st.nextToken()) - 1,
                parseInt(st.nextToken()) - 1,
                parseInt(st.nextToken()) - 1
        );
        dist[start.x][start.y][start.dir] = 1;

        Queue<Status> q = new ArrayDeque<>();
        q.add(start);
        while (!q.isEmpty()) {
            Status cur = q.poll();
            int cx = cur.x; int cy = cur.y;
            int cdir = cur.dir;
            int cdist = dist[cx][cy][cdir];

            int cnt = 0;
            while (++cnt <= 3) {
                int nx = cx + cnt * dx[cdir];
                int ny = cy + cnt * dy[cdir];
                if (oob(nx, ny) || isBlocked[nx][ny]) break;
                if (dist[nx][ny][cdir] != 0) continue;
                dist[nx][ny][cdir] = cdist + 1;
                q.add(new Status(nx, ny, cdir));
            }

            int[] ndirs = new int[]{2, 3};
            if (cdir == 2 || cdir == 3) { ndirs = new int[]{0, 1}; }
            for (int ndir : ndirs) {
                if (dist[cx][cy][ndir] != 0) continue;
                dist[cx][cy][ndir] = cdist + 1;
                q.add(new Status(cx, cy, ndir));
            }
        }

        st = new StringTokenizer(br.readLine());
        int gx = parseInt(st.nextToken()) - 1;
        int gy = parseInt(st.nextToken()) - 1;
        int gdir = parseInt(st.nextToken()) - 1;
        System.out.println(dist[gx][gy][gdir] - 1);
    }
}