import java.io.*;
import java.util.*;

public class Main {

    static int[][] b = new int[20][20];
    static int[] dx = new int[]{1, 0, 1, 1};
    static int[] dy = new int[]{0, 1, 1, -1};
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static boolean oob(int x, int y) {
        return (x >= 20 || x < 1 || y >= 20 || y < 1);
    }

    static boolean solve(final int x, final int y) throws IOException {
        final int side = b[x][y];
        int cx, cy, ansX, ansY;
        for (int dir = 0; dir < 4; dir++) {
            ansX = x; ansY = y; 
            cx = x; cy = y;
            int cnt = 1;
            while (true) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if(oob(nx, ny) || b[nx][ny] != side) break;
                cnt++; cx = nx; cy = ny;
                if (cy < ansY) {
                    ansY = cy; ansX = cx;
                } else if (cy == ansY) {
                    ansX = Math.min(ansX, cx);
                }
            }
            cx = x; cy = y;
            while (true) {
                int nx = cx - dx[dir];
                int ny = cy - dy[dir];
                if(oob(nx, ny) || b[nx][ny] != side) break;
                cnt++; cx = nx; cy = ny;
                if (cy < ansY) {
                    ansY = cy; ansX = cx;
                } else if (cy == ansY) {
                    ansX = Math.min(ansX, cx);
                }
            }
            if (cnt == 5) {
                bw.write(String.valueOf(side) + '\n');
                bw.write(String.valueOf(ansX) + ' ' + String.valueOf(ansY));
                bw.flush();
                return true;
            }
        }
        return false;
    }

    public static void main(String args[]) throws IOException {
        for (int i = 1; i < 20; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j < 20; j++)
                b[i][j] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < 20; i++)
            for (int j = 1; j < 20; j++) {
                if (b[i][j] == 0) continue;
                if (solve(i, j)) return;
            }
        bw.write("0");
        bw.flush();
    }
}