import java.io.*;
import static java.lang.Integer.parseInt;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int[][] calc = new int[4][10002];

    public static void main(String[] args) throws IOException {

        // setup
        for (int j = 0; j <= 10_000; j++)
            calc[1][j] = 1;

        for (int i = 2; i <= 3; i++) {
            for (int j = i; j <= 10_000; j++) {
                for (int k = 1; k <= i; k++) {
                    if (j - k < 0) continue;
                    calc[i][j] += calc[k][j - i];
                }
            }
        }

        int t = parseInt(br.readLine());
        while (t-- > 0) {
            int x = parseInt(br.readLine());
            int ans = calc[1][x] + calc[2][x] + calc[3][x];
            sb.append(ans).append('\n');
        }
        System.out.print(sb);
    }
}