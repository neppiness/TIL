import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static char[][] b = new char[7][7];
    static Coord[] vct = new Coord[36];
    static Coord[] t = new Coord[5];

    static int[] dx = new int[]{1, 0, -1, 0};
    static int[] dy = new int[]{0, 1, 0, -1};

    static boolean isPossible;
    static int vctcnt, tcnt;
    static int n;

    static class Coord {
        int x, y;
        Coord(int x_, int y_) { this.x = x_; this.y = y_; }

        void setChar(char c) {
            b[this.x][this.y] = c;
        }
    }
    
    static boolean oob(int x, int y) {
        return (x >= n || x < 0 || y >= n || y < 0);
    }

    static boolean check() {
        for (int i = 0; i < tcnt; i++) {
            Coord cur = t[i];
            int cx = cur.x; int cy = cur.y;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                while (!oob(nx, ny) && b[nx][ny] != 'O') {
                    if (b[nx][ny] == 'S') return false;
                    nx += dx[dir]; ny += dy[dir];
                }
            }
        }
        return true;
    }

    static void solve(int st, int lv) {
        if (lv == 0) {
            isPossible = (isPossible || check());
            return;
        }
        for (int i = st; i < vctcnt; i++) {
            vct[i].setChar('O');
            solve(i + 1, lv - 1);
            vct[i].setChar('X');
        }
    }

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                char c = (st.nextToken()).charAt(0);
                if (c == 'X') vct[vctcnt++] = new Coord(i, j);
                if (c == 'T') t[tcnt++] = new Coord(i, j);
                b[i][j] = c;
            }
        }

        for (int i = 0; i < vctcnt; i++)
            solve(i, 3);

        if (isPossible) System.out.print("YES");
        else System.out.print("NO");
    }
}