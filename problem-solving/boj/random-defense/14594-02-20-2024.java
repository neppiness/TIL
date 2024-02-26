import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[] wall = new boolean[n + 1];
        Arrays.fill(wall, true);

        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            for (int j = x; j < y; j++) {
                wall[j] = false;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (wall[i]) {
                ans++;
            }
        }
        System.out.print(ans);
    }

}

