import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, d, k, c, ans = 0;
    static int a[];
    static HashMap<Integer, Integer> dict = new HashMap<>();

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        c = Integer.parseInt(st.nextToken());
        dict.put(c, 1);

        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = Integer.parseInt(br.readLine());
        int start = 0, end = 0;
        for (; end < k; end++) {
            if (dict.get(a[end]) == null) dict.put(a[end], 1);
            else dict.put(a[end], dict.get(a[end]) + 1);
        }
        ans = Math.max(ans, dict.size());
        // end == k
        if (end == n) end = 0;
        for (int i = 0; i < n; i++) {
            if (dict.get(a[end]) == null) dict.put(a[end], 1);
            else dict.put(a[end], dict.get(a[end]) + 1);

            dict.put(a[start], dict.get(a[start]) - 1);
            if (dict.get(a[start]) == 0) dict.remove(a[start]);

            ans = Math.max(ans, dict.size());

            start++; end++;
            if (start == n) start = 0;
            if (end == n) end = 0;
        }
        System.out.print(ans);
    }
}