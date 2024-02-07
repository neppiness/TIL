import java.io.*;
import java.util.*;
import static java.lang.Integer.parseInt;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int dx[] = new int[]{0, 1, 0, -1};
    static int dy[] = new int[]{1, 0, -1, 0};

    static int n, m; // n: 가로 길이, m: 세로 길이
    static int[][] b;
    static int[][] dist;

    static class Coord {
        public int x, y;
        Coord(int x_, int y_) { this.x = x_; this.y = y_; }
    }

    static boolean isValid(int x, int y) {
        if (x == 0 || x == m) return (y >= 0 && y <= n);
        if (y == 0 || y == n) return (x >= 0 && x <= m);
        return false;
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = parseInt(st.nextToken());
        m = parseInt(st.nextToken());

        b = new int[m + 1][n + 1];
        dist = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
            Arrays.fill(dist[i], -1);

        int no = parseInt(br.readLine());
        for (int i = 1; i <= no; i++) {
            st = new StringTokenizer(br.readLine());
            int code = parseInt(st.nextToken());
            int d = parseInt(st.nextToken());

            if (code == 1) b[0][d] = i;       // 상점이 블록의 북쪽에 있는 경우
            else if (code == 2) b[m][d] = i;  // 상점이 블록의 남쪽에 있는 경우
            else if (code == 3) b[d][0] = i;  // 상점이 블록의 서쪽에 있는 경우
            else b[d][n] = i;                // 상점이 블록의 동쪽에 있는 경우
        }

        st = new StringTokenizer(br.readLine());
        int code = parseInt(st.nextToken());
        int d = parseInt(st.nextToken());

        Coord st;
        if (code == 1) st = new Coord(0, d);
        else if (code == 2) st = new Coord(m, d);
        else if (code == 3) st = new Coord(d, 0);
        else st = new Coord(d, n);

        Queue<Coord> q = new ArrayDeque<>();
        q.add(st); dist[st.x][st.y] = 0;

        while (!q.isEmpty()) {
            Coord cur = q.poll();
            int cx = cur.x; int cy = cur.y;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (!isValid(nx, ny) || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[cx][cy] + 1;
                q.add(new Coord(nx, ny));
            }
        }

        int ans = 0;
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) {
                if (b[i][j] == 0) continue;
                ans += dist[i][j];
            }
            
        System.out.println(ans);
    }
}