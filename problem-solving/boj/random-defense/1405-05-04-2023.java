import java.io.*;
import java.util.*;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static double ans = 0;
    static int n;
    static int pos[] = new int[4];
    static boolean[][] vis = new boolean[31][31];

    static int dx[] = new int[]{0, 0, 1, -1};
    static int dy[] = new int[]{1, -1, 0, 0};

    static void genPath(int lv, int cx, int cy) {
        double possibility = 1;
        if (lv == n) {
            for (int i = 0; i < n; i++) {
                int diridx = sb.charAt(i) - '0';
                possibility *= (double)pos[diridx] / 100;
            }
            ans += possibility;
            return;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            sb.append(dir);
            genPath(lv + 1, nx, ny);
            vis[nx][ny] = false;
            sb.deleteCharAt(lv);
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        for (int i = 0; i < 4; i++)
            pos[i] = Integer.parseInt(st.nextToken());

        vis[15][15] = true;
        genPath(0, 15, 15);
        System.out.println(String.format("%.10f", ans));
    }
}