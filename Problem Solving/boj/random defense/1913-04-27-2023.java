import java.io.*;

public class Main {

    public static int[][] b;
    public static int c, x;
    public static int dx[] = new int[]{1, 0, -1, 0};
    public static int dy[] = new int[]{0, 1, 0, -1};

    public static int ansX, ansY;

    public static void solve(int len) {
        int cx = c - len/2;
        int cy = c - len/2;

        b[cx][cy] = len*len;
        if (x == len * len) {
            ansX = cx + 1;
            ansY = cy + 1;
        }

        int dir = 0;
        while (dir < 4) {
            for (int i = 1; i < len; i++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (b[nx][ny] != 0) continue;
                b[nx][ny] = b[cx][cy] - 1;
                if (b[nx][ny] == x) {
                    ansX = nx + 1;
                    ansY = ny + 1;
                }
                cx = nx; cy = ny;
            }
            dir++;
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        x = Integer.parseInt(br.readLine());

        b = new int[n][n]; c = n/2;
        b[c][c] = 1;

        if (x == 1) {
            ansX = c + 1;
            ansY = c + 1;
        }
        for (int i = 3; i <= n; i += 2) solve(i);

        for (int[] p : b) {
            for (int q : p) bw.write(String.valueOf(q) + " ");
            bw.write("\n");
        }
        bw.write(String.valueOf(ansX) + " " + String.valueOf(ansY));
        bw.flush();
    }
}