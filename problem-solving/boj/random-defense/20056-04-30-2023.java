import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int n, m, k;

    static int dx[] = new int[]{-1, -1, 0, 1, 1, 1, 0, -1};
    static int dy[] = new int[]{0, 1, 1, 1, 0, -1, -1, -1};

    static class Fireball {
        public int x, y, m, s, d, id;

        Fireball(int x_, int y_, int m_, int s_, int d_) {
            this.m = m_; this.s = s_; this.d = d_;
            setCoord(x_, y_);
            setId();
        }

        void move() {
            int nx = ((this.x + dx[d] * s) % n + n) % n;
            int ny = ((this.y + dy[d] * s) % n + n) % n;
            setCoord(nx, ny);
            setId();
        }

        void setCoord(int x_, int y_) { this.x = x_; this.y = y_; }

        void setId() { this.id = this.x * n + this.y; }
    }

    static Map<Integer, ArrayList<Fireball>> board = new HashMap<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n*n; i++)
            board.put(i, new ArrayList<Fireball>());

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            Fireball fb = new Fireball(
                    Integer.parseInt(st.nextToken()) - 1,
                    Integer.parseInt(st.nextToken()) - 1,
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken())
            );
            board.get(fb.id).add(fb);
        }

        Queue<Fireball> q = new ArrayDeque<>();
        while (k-- > 0) {
            for (int id = 0; id < n*n; id++) {
                for (Fireball fb : board.get(id)) q.add(fb);
                board.get(id).clear();
            }

            while (!q.isEmpty()) {
                Fireball fb = q.poll();
                fb.move();
                board.get(fb.id).add(fb);
            }

            // 동일한 위치에 있는 파이어볼 합치기
            for (int id = 0; id < n*n; id++) {
                ArrayList<Fireball> fireballs = board.get(id);
                int noOfFireballs = fireballs.size();
                if (noOfFireballs < 2) continue;

                int new_m = 0, new_s = 0, dir = 0;
                for (Fireball fb : fireballs) {
                    new_m += fb.m;
                    new_s += fb.s;
                    dir = fb.d;
                }

                new_m /= 5; new_s /= noOfFireballs;
                dir %= 2;

                boolean check = true;
                for (Fireball fb : fireballs) {
                    check = (check && ((fb.d % 2) == dir));
                }
                int[] dirs = new int[]{1, 3, 5, 7};
                if (check) dirs = new int[]{0, 2, 4, 6};

                board.get(id).clear();
                if (new_m == 0) continue;
                int cx = id / n, cy = id % n;
                for (int i = 0; i < 4; i++) {
                    board.get(id).add(new Fireball(cx, cy, new_m, new_s, dirs[i]));
                }
            }
        }

        int ans = 0;
        for (int id = 0; id < n*n; id++) {
            ArrayList<Fireball> fireballs = board.get(id);
            for (Fireball fb : fireballs) ans += fb.m;
        }
        System.out.print(ans);
    }
}