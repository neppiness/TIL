import java.io.*;
import java.util.*;

public class Main {

    static int[] dist = new int[502];
    static List<List<Integer>> adj = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj.get(a).add(b);
            adj.get(b).add(a);
        }

        Arrays.fill(dist, -1);
        dist[1] = 0;
        Queue<Integer> q = new ArrayDeque<>();
        q.add(1);

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int nxt : adj.get(cur)) {
                if (dist[nxt] != -1) {
                    continue;
                }
                dist[nxt] = dist[cur] + 1;
                q.add(nxt);
            }
        }

        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (dist[i] == -1 || dist[i] > 2) {
                continue;
            }
            ans++;
        }
        System.out.print(ans);
    }

}

