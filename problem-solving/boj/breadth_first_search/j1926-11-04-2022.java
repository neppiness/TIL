import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {
    public static int n, m;
    public static int[][] b;
    public static boolean[][] vis;
    class Coord {
        int x, y;
        public Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int solve(int cx, int cy) {
        int[] dx = new int[] {1, 0, -1, 0};
        int[] dy = new int[] {0, 1, 0, -1};

        int area = 1;
        Coord cur = new Coord(cx, cy);
        Queue<Coord> q = new ArrayDeque<>();
        q.add(cur);
        vis[cx][cy] = true;

        int nx, ny;
        Coord nxt;
        while(!q.isEmpty()) {
            cur = q.poll();
            for(int dir = 0; dir < 4; dir++) {
                nx = cur.x + dx[dir];
                ny = cur.y + dy[dir];

                if(nx >= n || nx < 0) continue;
                if(ny >= m || ny < 0) continue;
                if(vis[nx][ny]) continue;
                if(b[nx][ny] == 0) continue;

                vis[nx][ny] = true;
                area++;
                nxt = new Coord(nx, ny);
                q.add(nxt);
            }
        }
        return area;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        b = new int[n][m];
        vis = new boolean[n][m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                vis[i][j] = false;

        String inputLine;
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++)
                b[i][j] = Integer.parseInt(st.nextToken());
        }

        int a, mx = 0;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if((b[i][j] == 1) && !vis[i][j]) {
                    a = new Main().solve(i, j);
                    ans.add(a);
                    mx = Math.max(mx, a);
                }
        bw.write(String.valueOf(ans.size()));
        bw.newLine();
        bw.write(String.valueOf(mx));
        bw.flush();
    }
}