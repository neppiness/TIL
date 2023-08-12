import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static final int dx[] = new int[]{0, 0, -1, 1, 1, 1, -1, -1};
    static final int dy[] = new int[]{1, -1, 0, 0, 1, -1, 1, -1};

    static final String[] moves = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};

    static int[][] b = new int[8][8];
    static int[] x = new int[3]; // 킹의 x좌표: x[1], 돌의 x좌표: x[2]
    static int[] y = new int[3]; // 킹의 x좌표: y[1], 돌의 x좌표: y[2]

    static HashMap<String, Integer> move = new HashMap<>();

    static boolean oob(int x, int y) {
        return (x >= 8 || x < 0 || y >= 8 || y < 0);
    }

    static void move() throws IOException {
        int dir = move.get(br.readLine());
        int kcx = x[1], kcy = y[1];
        int knx = kcx + dx[dir];
        int kny = kcy + dy[dir];

        if (oob(knx, kny)) return;
        // 킹의 다음 위치에 돌이 있는 경우
        if (b[knx][kny] == 2) {
            // 킹과 같은 방향으로 돌이 이동함
            int snx = knx + dx[dir];
            int sny = kny + dy[dir];
            // 돌이 경계 밖으로 나가면 이동 안 함
            if (oob(snx, sny)) return;
            // 돌이 보드 안에 있으면 자리 이동
            b[snx][sny] = 2; x[2] = snx; y[2] = sny;
            b[knx][kny] = 1; x[1] = knx; y[1] = kny;
        } else {
            b[knx][kny] = 1; x[1] = knx; y[1] = kny;
        }
        b[kcx][kcy] = 0;
    }

    public static void main(String args[]) throws IOException {
        for (int dir = 0; dir < 8; dir++)
            move.put(moves[dir], dir);

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= 2; i++) {
            char[] coords = st.nextToken().toCharArray();
            y[i] = (int)(coords[0] - 'A');
            x[i]= (int)(coords[1] - '1');
            b[x[i]][y[i]] = i;
        }
        int n = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) move();

        for (int i = 1; i <= 2; i++) {
            bw.write((char)(y[i] + 'A'));
            bw.write((char)(x[i] + '1'));
            bw.write('\n');
        }
        bw.flush();
    }
}