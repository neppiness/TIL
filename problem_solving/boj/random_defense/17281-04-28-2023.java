import java.io.*;
import java.util.*;

public class Main {

    static int ans, tmp, noOfInning;
    static int res[][];
    static int seq[] = new int[10]; // 타순
    static boolean isOccupied[] = new boolean[4]; // 1루, 2루, 3루에 선수가 있는지 표시.

    static void permutation(int no) { // no번 선수 타순 정하기
        if (no == 10) { simulation(); return; }
        for (int s = 1; s <= 9; s++) { // s번 타자로 no번 선수 등록하기
            if (seq[s] != 0) continue;
            seq[s] = no;
            permutation(no + 1);
            seq[s] = 0;
        }
    }

    static void progress(int x) {
        isOccupied[0] = true;
        for (int i = 3; i >= 0; i--) {
            if (!isOccupied[i]) continue;
            isOccupied[i] = false;
            if (i + x >= 4) { tmp++; continue; }
            isOccupied[i + x] = true;
        }
    }

    static void simulation() {
        int n = 0, st = 1; tmp = 0;
        while (n < noOfInning) {
            // 이닝이 시작될 떄 주자는 없다.
            Arrays.fill(isOccupied, false);
            int outCnt = 0;
            while (outCnt < 3) { // 3 아웃이면 이닝 종료
                int no = seq[st++];
                if (st == 10) st = 1;
                if (res[n][no] == 0) { outCnt++; continue; }
                progress(res[n][no]);
            }
            // 이닝 수 증가
            n++;
        }
        // 모든 이닝이 끝난 뒤 득점 수 갱신 가능성 확인
        ans = Math.max(tmp, ans);
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        noOfInning = Integer.parseInt(br.readLine());

        ans = 0;
        res = new int[noOfInning][10]; // 각 타자의 이닝 별 결과. 타자 번호는 1부터 9.
        for (int i = 0; i < noOfInning; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 9; j++)
                res[i][j] = Integer.parseInt(st.nextToken());
        }

        seq[4] = 1; // 4번 타자는 1번 선수.
        permutation(2); // 2번 선수부터 타순 정하기
        bw.write(String.valueOf(ans));
        bw.flush();
    }
}
