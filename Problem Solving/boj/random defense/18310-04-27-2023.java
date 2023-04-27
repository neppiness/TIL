import java.io.*;
import java.util.*;

public class Main {

    private static int min = 0x7f7f7f7f, ans = 0x7f7f7f7f, n;
    private static List<Integer> house = new ArrayList<>();

    public static int find(int tar) {
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int chk = house.get(mid);
            if (chk < tar) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    public static void calc(int idx) {
        int x = house.get(idx);
        int tot = 0;
        for (int h : house) { tot += Math.abs(h - x); }
        if (tot < min) {
            min = tot;
            ans = x;
            return;
        }
        if (tot == min) { ans = Math.min(ans, x); }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int tot = 0;
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());
            house.add(x);
            tot += x;
        }
        Collections.sort(house);

        int avg1 = tot / n;
        int avg2 = tot / n + 1;

        int idx1 = find(avg1);
        int idx2 = find(avg2);

        for (int x : new int[]{idx1 - 1, idx1, idx1 + 1, idx2 - 1, idx2, idx2 + 1}) {
            if(x >= n || x < 0) continue;
            calc(x);
        }
        bw.write(String.valueOf(ans));
        bw.flush();
    }
}
