import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, m;

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int ans;
        if (n == 1) ans = 1;
        else if (n == 2) {
            ans = Math.min((m + 1) / 2, 3);
        } else {
            if (m <= 6) ans = Math.min(4, m);
            else ans = m - 2;
        }

        System.out.print(ans);
    }
}