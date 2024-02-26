import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int[] cnt, a;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        cnt = new int[n + 1];
        a = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int end = 0;
        long ans = 0L;
        for (int start = 0; start < n; start++) {
            ans += (end - start + 1);
            while (end < n && cnt[a[end]] < 2) {
                cnt[a[end]]++;
                if (cnt[a[end]] >= 2) {
                    break;
                }
                end++;
            }
            cnt[a[start]]--;
        }
        System.out.print(ans);
    }

}

