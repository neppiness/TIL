import java.io.*;
import java.util.*;
import static java.lang.Integer.parseInt;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n;
    static int a[];

    static TreeSet<Integer> set = new TreeSet<>();

    static void solve(int lv, int st, int sum) {
        if (lv == 0) { set.add(sum); return; }
        for (int i = st; i < n; i++)
            solve(lv - 1, i + 1, sum + a[i]);
    }

    public static void main(String[] args) throws IOException {

        n = parseInt(br.readLine());
        a = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            a[i] = parseInt(st.nextToken());

        for (int i = 1; i <= n; i++)
            solve(i, 0, 0);

        int no = 1;
        while (no < 10) {
            Integer ceiling = set.ceiling(no);
            if (ceiling == null || no != ceiling) break;
            no++;
        }
        System.out.println(no);
    }
}