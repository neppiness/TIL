import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int n, m;
    static int[][] dist;
    static boolean[][] isBlocked;

    static int dx[] = new int[]{1, 0, -1, 0};
    static int dy[] = new int[]{0, 1, 0, -1};
    static Queue<Coord> q = new ArrayDeque<>();
    static Coord start;

    static class Coord {
        int x, y;
        Coord(int x_, int y_) { this.x = x_; this.y = y_; }
    }

    static boolean oob(int x, int y) {
        return (x >= n || x < 0 || y >= m || y < 0);
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken()); // 행 개수
        m = Integer.parseInt(st.nextToken()); // 열 개수

        isBlocked = new boolean[n][m];
        dist = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                int x = Integer.parseInt(st.nextToken());
                if (x == 0) isBlocked[i][j] = true;
                else dist[i][j] = -1;
                if (x == 2) start = new Coord(i, j);
            }
        }
        
        dist[start.x][start.y] = 0;
        q.add(start);
        while (!q.isEmpty()) {
            Coord cur = q.poll();
            int cx = cur.x, cy = cur.y;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (oob(nx, ny) || isBlocked[nx][ny]) continue;
                if (dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[cx][cy] + 1;
                q.add(new Coord(nx, ny));
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                sb.append(dist[i][j]).append(' ');
            sb.append('\n');
        }
        System.out.print(sb);
    }
}