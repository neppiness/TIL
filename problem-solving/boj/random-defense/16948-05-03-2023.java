import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static Coord start, end;

    static int n;
    static int[][] dist;

    static int dx[] = new int[]{-2, -2, 0, 0, 2, 2};
    static int dy[] = new int[]{-1, 1, -2, 2, -1, 1};

    static class Coord {
        public int x, y;
        Coord(int x_, int y_) {
            this.x = x_; this.y = y_;
        }
    }

    static boolean oob(int x, int y) {
        return (x >= n || x < 0 || y >= n || y < 0);
    }

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        dist = new int[n][n];

        int[] r = new int[2];
        int[] c = new int[2];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 2; i++) {
            r[i] = Integer.parseInt(st.nextToken());
            c[i] = Integer.parseInt(st.nextToken());
        }
        start = new Coord(r[0], c[0]);
        end = new Coord(r[1], c[1]);
        

        Queue<Coord> q = new ArrayDeque<Coord>();
        q.add(start); dist[start.x][start.y] = 1;
        while (!q.isEmpty()) {
            Coord cur = q.poll();
            for (int dir = 0; dir < 6; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (oob(nx, ny) || dist[nx][ny] != 0) continue;
                q.add(new Coord(nx, ny));
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
            }
        }

        int ans = dist[r[1]][c[1]];
        System.out.print(ans - 1);
    }
}