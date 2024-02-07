import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, ans;
    static boolean[] isUsed = new boolean[10];
    static int[] a = new int[10];

    static void solve(int lv, int sum) {
        if (lv == 0) {
            ans = Math.max(sum, ans);
            return;
        }

        for (int i = 1; i < n - 1; i++) {
            if (isUsed[i]) continue;
            isUsed[i] = true;
            int leftIndex = i;
            int rightIndex = i;
            while (isUsed[leftIndex]) leftIndex--;
            while (isUsed[rightIndex]) rightIndex++;
            solve(lv - 1, sum + a[leftIndex] * a[rightIndex]);
            isUsed[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            a[i] = Integer.parseInt(st.nextToken());
        
        solve(n - 2, 0);
        System.out.println(ans);
    }
}