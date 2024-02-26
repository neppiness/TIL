import java.io.*;
import java.util.*;

public class Main {

    static int[] p = new int[100_002];
    static List<List<Integer>> adj = new ArrayList<>();

    static void dfs(int cur) {
        for (int nxt : adj.get(cur)) {
            if (p[nxt] != 0) {
                continue;
            }
            p[nxt] = cur;
            dfs(nxt);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 1; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj.get(a).add(b);
            adj.get(b).add(a);
        }

        dfs(1);

        StringBuilder sb = new StringBuilder();
        for (int i = 2; i <= n; i++) {
            sb.append(p[i]).append('\n');
        }
        System.out.print(sb);
    }

}

