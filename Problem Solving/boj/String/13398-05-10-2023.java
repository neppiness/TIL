import java.io.*;
import java.util.*;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    final static int MINF = -0x3f3f3f3f;
    static int ans = MINF;
    static int[][] cache = new int[100_002][2];

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i <= 100_000; i++)
            Arrays.fill(cache[i], MINF);

        int a = Integer.parseInt(st.nextToken());
        cache[0][0] = a; ans = Math.max(a, ans);

        for (int i = 1; i < n; i++) {
            a = Integer.parseInt(st.nextToken());
            cache[i][0] = Math.max(cache[i - 1][0], a); // 덮어쓰기(시작점 새로 잡기)
            cache[i][0] = Math.max(cache[i - 1][0] + a, cache[i][0]); // 현재 항 더하기
            cache[i][1] = Math.max(cache[i - 1][0], cache[i][1]); // 현재 항 무시하기
            cache[i][1] = Math.max(cache[i - 1][1] + a, cache[i - 1][1]); // 현재 항 더하기
            ans = Math.max(ans, Math.max(cache[i][0], cache[i][1]));
        }
        System.out.print(ans);
    }
}