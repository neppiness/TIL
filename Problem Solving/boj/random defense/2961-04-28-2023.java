import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] sourTaste = new int[n];
        int[] bitterTaste = new int[n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            sourTaste[i] = Integer.parseInt(st.nextToken());
            bitterTaste[i] = Integer.parseInt(st.nextToken());
        }

        int mx = (1 << n);
        int ans = 0x7f7f7f7f;
        for (int comb = 1; comb < mx; comb++) {
            int totalSourTaste = 1;
            int totalBitterTaste = 0;
            for (int i = 0; i < n; i++) {
                int chk = (1 << i);
                if ((chk & comb) == 0) continue;
                totalSourTaste *= sourTaste[i];
                totalBitterTaste += bitterTaste[i];
            }
            int diff = Math.abs(totalSourTaste - totalBitterTaste);
            ans = Math.min(ans, diff);
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }
}