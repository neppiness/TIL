import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[][] synergy = new int[22][22];
    static boolean[] team = new boolean[22];

    static int n;
    static int ans = 0x7f7f7f7f;

    static int calc(List<Integer> teamList) {
        int sum = 0;
        for (int i = 0; i < teamList.size(); i++) {
            for (int j = i + 1; j < teamList.size(); j++) {
                int u = teamList.get(i);
                int v = teamList.get(j);
                sum += synergy[u][v] + synergy[v][u];
            }
        }
        return sum;
    }

    static void calc() {
        List<Integer> teamZero = new ArrayList<>();
        List<Integer> teamOne = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (team[i]) teamOne.add(i);
            else teamZero.add(i);
        }
        ans = Math.min(ans, Math.abs(calc(teamZero) - calc(teamOne)));
    }

    static void solve(int lv, int st) {
        if (lv == 0) { calc(); return; }
        for (int i = st; i < n; i++) {
            team[i] = true;
            solve(lv - 1, i + 1);
            team[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++)
                synergy[i][j] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= n/2; i++)
            solve(i, 0);
        System.out.println(ans);
    }
}