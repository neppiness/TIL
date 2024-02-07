import java.io.*;
import java.util.*;

public class Main {

    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int n, m, seq, ans;
    static int[][] adj, id;

    static int[] dx = new int[]{0, -1, 0, 1};
    static int[] dy = new int[]{-1, 0, 1, 0};

    static ArrayList<Integer> sizes = new ArrayList<>();

    static class Coord {
        int x, y;
        Coord(int x_, int y_) { this.x = x_; this.y = y_; }
    }

    static void solve(int i, int j) {
        ArrayDeque<Coord> q = new ArrayDeque<>();
        q.add(new Coord(i ,j));
        id[i][j] = seq++;
        int size = 1;

        while (!q.isEmpty()) {
            Coord cur = q.poll();
            int cx = cur.x, cy = cur.y;
            for (int dir = 0; dir < 4; dir++) {
                int lg = (1 << dir);
                if ((adj[cx][cy] & lg) != 0) continue;
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (id[nx][ny] != -1) continue;
                size++;
                id[nx][ny] = id[cx][cy];
                q.add(new Coord(nx, ny));
            }
        }
        sizes.add(size);
    }

    static boolean oob(int x, int y) {
        return (x >= m || x < 0 || y >= n || y < 0);
    }

    static void check(int cx, int cy) {
        int curId = id[cx][cy];
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (oob(nx, ny)) continue;
            int nxtId = id[nx][ny];
            if (curId == nxtId) continue;
            int tmpSize = sizes.get(curId) + sizes.get(nxtId);
            ans = Math.max(ans, tmpSize);
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        adj = new int[m][n];
        id = new int[m][n];

        for (int i = 0; i < m; i++)
            Arrays.fill(id[i], -1);

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++)
                adj[i][j] = Integer.parseInt(st.nextToken());
        }
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (id[i][j] != -1) continue;
                solve(i, j);
            }
        
        int mx = 0;
        for (int sz : sizes)
            mx = Math.max(mx, sz);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                check(i, j);
        
        sb.append(sizes.size()).append('\n');
        sb.append(mx).append('\n');
        sb.append(ans);

        System.out.println(sb);
    }
}