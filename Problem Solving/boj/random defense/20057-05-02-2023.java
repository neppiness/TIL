import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, ans;
    static int sp, dir;

    static int[] dx = new int[]{0, 1, 0, -1};
    static int[] dy = new int[]{-1, 0, 1, 0};
    static int[][] dust;

    static boolean oob(int x, int y) {
        return (x >= n || x < 0 || y >= n || y < 0);
    }

    static class Tornado {
        public int x, y;

        Tornado() {
            this.x = n/2; this.y = n/2;
        }

        public void move() {
            this.x += dx[dir];
            this.y += dy[dir];

            
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
        sp = n - 1; tnd.move();
        System.out.print(ans);
    }
}