import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, m;
    static int[][] block;
    static int[] dist;
    static int coordX, coordY;

    static int[] dx = new int[]{1, 0, -1, 0};
    static int[] dy = new int[]{0, 1, 0, -1};

    static boolean isValidNxtCoord(int x, int y) {
        if (x == 0 || x == m) { return (y <= n && y >= 0); }
        if (y == 0 || y == n) { return (x <= m && x >= 0); }
        return false;
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = parseInt(st.nextToken()); // 가로 길이, j, y로 제어
        m = parseInt(st.nextToken()); // 세로 길이, i, x로 제어

        block = new int[m + 1][n + 1];
        int no = parseInt(br.readLine()); // 상점 개수
        dist = new int[no + 1]; // 상점 거리, 인덱스는 1부터 시작
        Arrays.fill(dist, 0x7f7f7f7f);
        for (int i = 1; i <= no; i++) { // i: 상점 인덱스
            st = new StringTokenizer(br.readLine());
            int code = parseInt(st.nextToken()); // 상점이 위치한 방향
            int d = parseInt(st.nextToken()); // 거리

            if (code == 1) { // 상점이 블록의 북쪽에 있는 경우
                block[0][d] = i;
            } else if (code == 2) { // 상점이 블록의 남쪽에 있는 경우
                block[m][d] = i;
            } else if (code == 3) { // 상점이 블록의 서쪽에 있는 경우
                block[d][0] = i;
            } else { // 상점이 블록의 동쪽에 있는 경우
                block[d][n] = i;
            }
        }

        st = new StringTokenizer(br.readLine());
        int code = parseInt(st.nextToken()); // 상점이 위치한 방향
        int d = parseInt(st.nextToken()); // 거리
        if (code == 1) { // 상점이 블록의 북쪽에 있는 경우
            coordX = 0; coordY = d;
        } else if (code == 2) { // 상점이 블록의 남쪽에 있는 경우
            coordX = m; coordY = d;
        } else if (code == 3) { // 상점이 블록의 서쪽에 있는 경우
            coordX = d; coordY = 0;
        } else { // 상점이 블록의 동쪽에 있는 경우
            coordX = d; coordY = n;
        }

        int dir;
        // 동근이 위치에서부터 반시계방향으로 도는 경우
        if (code == 1) dir = 3;
        else if (code == 2) dir = 1;
        else if (code == 3) dir = 0;
        else dir = 2;

        int cnt = 0;
        int cx = coordX; int cy = coordY;
        int nx; int ny;
        do {
            if (block[cx][cy] != 0)
                dist[block[cx][cy]] = Math.min(cnt, dist[block[cx][cy]]);
            nx = cx + dx[dir]; ny = cy + dy[dir];
            while (!isValidNxtCoord(nx, ny)) {
                if (++dir >= 4) dir = 0;
                nx = cx + dx[dir]; ny = cy + dy[dir];
            }
            cnt++; cx = nx; cy = ny;
        } while (cx != coordX || cy != coordY);

        // 동근이 위치에서부터 시계방향으로 도는 경우
        if (code == 1) dir = 3;
        else if (code == 2) dir = 1;
        else if (code == 3) dir = 0;
        else dir = 2;

        cnt = 0;
        cx = coordX; cy = coordY;
        do {
            if (block[cx][cy] != 0)
                dist[block[cx][cy]] = Math.min(cnt, dist[block[cx][cy]]);
            nx = cx - dx[dir]; ny = cy - dy[dir];
            if (!isValidNxtCoord(nx, ny)) {
                if (--dir < 0) dir = 3;
                nx = cx - dx[dir]; ny = cy - dy[dir];
            }
            cnt++; cx = nx; cy = ny;
        } while (cx != coordX || cy != coordY);

        int ans = 0;
        System.out.println(ans);
    }
}