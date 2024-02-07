import java.io.*;
import java.util.*;


public class Main {

    static final int INF = 0x3f3f3f3f;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int n;
    static int[][] dist;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        dist = new int[n][n];

        for (int[] d : dist)
            Arrays.fill(d, INF);
        
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int i = 0; i < n; i++) {
            String input = br.readLine();
            for (int j = 0; j < n; j++) {
                if (input.charAt(j) == 'Y') {
                    dist[i][j] = 1;
                    dist[j][i] = 1;
                }
            }
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dist[i][j] <= 2) cnt++;
            }
            ans = Math.max(ans, cnt);
        }
        System.out.print(ans);
    }
}
