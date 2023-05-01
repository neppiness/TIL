import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, m, d, s;

    static int[] dx = new int[]{0, -1, -1, -1, 0, 1, 1, 1};
    static int[] dy = new int[]{-1, -1, 0, 1, 1, 1, 0, -1};

    static class Cloud {
        public int x, y;
        Cloud(int x_, int y_) { this.x = x_; this.y = y_; }

        void move() {
            int nx = this.x + s*dx[d - 1];
            int ny = this.y + s*dy[d - 1];
            this.x = ((nx % n) + n) % n;
            this.y = ((ny % n) + n) % n;
        }
    }

    static boolean oob(int x, int y) {
        return (x >= n || x < 0 || y >= n || y < 0);
    }

    static class Basket {
        public int[][] w, inc;
        public boolean[][] wasCloudHere;

        Basket(int n_) {
            this.w = new int[n_][n_];
            this.inc = new int[n_][n_];
            this.wasCloudHere = new boolean[n_][n_];
        }

        void waterCopyBugMagic(int cx, int cy) {
            this.w[cx][cy] += this.inc[cx][cy];
        }


        void waterIncCalc() {
            for (int cx = 0; cx < n; cx++)
                for (int cy = 0; cy < n; cy++) {
                    this.inc[cx][cy] = 0;
                    for (int dir = 1; dir < 8; dir += 2) {
                        int nx = cx + dx[dir];
                        int ny = cy + dy[dir];
                        if (oob(nx, ny) || this.w[nx][ny] == 0) continue;
                        this.inc[cx][cy]++;
                    }
                }
        }
    }

    static Basket b;
    static ArrayList<Cloud> clouds = new ArrayList<>();

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        b = new Basket(n);

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++)
                b.w[i][j] = Integer.parseInt(st.nextToken());
        }

        clouds.add(new Cloud(n - 1, 0));
        clouds.add(new Cloud(n - 1, 1));
        clouds.add(new Cloud(n - 2, 0));
        clouds.add(new Cloud(n - 2, 1));

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            d = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());
            for (Cloud c : clouds) {
                c.move();
                b.w[c.x][c.y]++;
                b.wasCloudHere[c.x][c.y] = true;
            }

            b.waterIncCalc();
            for (Cloud c : clouds)
                b.waterCopyBugMagic(c.x, c.y);
            clouds.clear();

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (!b.wasCloudHere[i][j] && b.w[i][j] >= 2) {
                        b.w[i][j] -= 2;
                        clouds.add(new Cloud(i, j));
                    }
                    b.wasCloudHere[i][j] = false;
                }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans += b.w[i][j];
        System.out.print(ans);
    }
}
