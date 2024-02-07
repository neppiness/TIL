import java.io.*;
import java.util.*;
import static java.lang.Integer.parseInt;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, ans;
    static int[] damage, pleasure;

    static void solve(int lv, int st, int totP, int hp) {
        if (lv == 0) {
            if (hp <= 0) return;
            ans = Math.max(ans, totP); return;
        }
        for (int i = st; i < n; i++)
            solve(lv - 1, i + 1, totP + pleasure[i], hp - damage[i]);
    }

    public static void main(String[] args) throws IOException {

        n = parseInt(br.readLine());
        damage = new int[n];
        pleasure = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            damage[i] = parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            pleasure[i] = parseInt(st.nextToken());

        for (int no = 1; no <= n; no++)
            solve(no, 0, 0, 100);

        System.out.println(ans);
    }
}