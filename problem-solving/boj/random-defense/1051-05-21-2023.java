import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int ans;
    static int n, m;
    static char[][] b = new char[52][52];

    static boolean solve(int size) {
        for (int i = 0; i + size - 1 < m; i++) {
            for (int j = 0; j + size - 1 < n; j++) {
                int ii = i + size - 1;
                int jj = j + size - 1;
                if (b[i][j] != b[ii][j]) continue;
                if (b[ii][j] != b[ii][jj]) continue;
                if (b[ii][jj] != b[i][jj]) continue;
                if (b[i][jj] != b[i][j]) continue;
                return true;
            }
        }
        return false;
    }


    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        for (int i = 0; i < m; i++) {
            char[] input = br.readLine().toCharArray();
            for (int j = 0; j < n; j++)
                b[i][j] = input[j];
        }

        for (int size = 1; size <= 50; size++)
            if (solve(size)) ans = Math.max(size, ans);

        System.out.println(ans * ans);
    }
}