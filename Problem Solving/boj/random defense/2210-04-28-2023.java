import java.io.*;
import java.util.*;

public class Main {

    static int[][] b = new int[5][5];
    static int dx[] = new int[]{1, 0, -1, 0};
    static int dy[] = new int[]{0, 1, 0, -1};

    static Map<Integer, Boolean> m = new HashMap<>();

    public static boolean outOfBound(int x, int y) {
        return (x >= 5 || x < 0 || y >= 5 || y < 0);
    }

    public static void solve(int x, int y, int lv, int tot) {
        if (lv == 6) {
            m.put(tot, true);
            return;
        }
        tot *= 10;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (outOfBound(nx, ny)) continue;
            solve(nx, ny, lv + 1, tot + b[nx][ny]);
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++)
                b[i][j] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                solve(i, j, 0, 0);
        
        bw.write(String.valueOf(m.size()));
        bw.flush();
    }
}