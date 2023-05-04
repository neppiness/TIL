import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static StringBuilder sb = new StringBuilder();

    static int n, ans;
    static int sp, dir;

    static int[] dx = new int[]{0, 1, 0, -1};
    static int[] dy = new int[]{-1, 0, 1, 0};

    static final int[] per = new int[]{7, 7, 2, 2, 10, 10, 1, 1, 5};
    static int[][] dust;

    static boolean oob(int x, int y) {
        return (x >= n || x < 0 || y >= n || y < 0);
    }

    static class Tornado {
        public int x, y;

        Tornado() { this.x = n/2; this.y = n/2; }

        void spreadDust() {
            int d = dust[this.x][this.y];
            int[] deltaDust = new int[10];
            int sum = 0;
            for (int i = 0; i < 9; i++) {
                deltaDust[i] = d * per[i] / 100;
                sum += deltaDust[i];
            }
            deltaDust[9] = d - sum;

            int[] dirs = new int[]{dir, dir + 1, dir + 2, dir + 3};
            for (int i = 1; i < 4; i++)
                if (dirs[i] >= 4) dirs[i] -= 4;
            int[] nx = new int[]{
                    this.x + dx[dirs[1]], this.x + dx[dirs[3]],
                    this.x + 2*dx[dirs[1]], this.x + 2*dx[dirs[3]],
                    this.x + dx[dirs[0]] + dx[dirs[1]], this.x + dx[dirs[0]] + dx[dirs[3]],
                    this.x + dx[dirs[2]] + dx[dirs[1]], this.x + dx[dirs[2]] + dx[dirs[3]],
                    this.x + 2*dx[dirs[0]], this.x + dx[dirs[0]]
            };
            int[] ny = new int[]{
                    this.y + dy[dirs[1]], this.y + dy[dirs[3]],
                    this.y + 2*dy[dirs[1]], this.y + 2*dy[dirs[3]],
                    this.y + dy[dirs[0]] + dy[dirs[1]], this.y + dy[dirs[0]] + dy[dirs[3]],
                    this.y + dy[dirs[2]] + dy[dirs[1]], this.y + dy[dirs[2]] + dy[dirs[3]],
                    this.y + 2*dy[dirs[0]], this.y + dy[dirs[0]]
            };

            for (int i = 0; i < 10; i++) {
                if (oob(nx[i], ny[i])) {
                    ans += deltaDust[i];
                    continue;
                }
                dust[nx[i]][ny[i]] += deltaDust[i];
            }
        }

        public void move() {
            this.x += dx[dir];
            this.y += dy[dir];
            spreadDust();
        }
    }

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        dust = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++)
                dust[i][j] = Integer.parseInt(st.nextToken());
        }

        Tornado tnd = new Tornado();
        sp = 1; dir = 0;

        while (sp < n) {
            int cycle = 2;
            while (cycle-- > 0) {
                for (int s = 0; s < sp; s++)
                    tnd.move();
                dir++;
                if(dir == 4) dir = 0;
            }
            sp++;
        }
        sp = n - 1;
        for (int s = 0; s < sp; s++)
            tnd.move();
        System.out.print(ans);
    }
}
