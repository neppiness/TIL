import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int n, m;
    static int[] indegree = new int[1002];
    static int[] dist = new int[1002];

    static List<List<Integer>> adj = new ArrayList<>();
    static Queue<Integer> q = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= n; i++)
            adj.add(new ArrayList<>());

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            indegree[v]++;
            adj.get(u).add(v);
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] != 0) continue;
            q.add(i); dist[i] = 1;
        }

        while (!q.isEmpty()) {
            int cur = q.poll();
            List<Integer> adjCur = adj.get(cur);
            for (int nxt : adjCur) {
                if (--indegree[nxt] != 0) continue;
                q.add(nxt); dist[nxt] = dist[cur] + 1;
            }
        }

        for (int i = 1; i <= n; i++) sb.append(dist[i]).append(' ');
        System.out.print(sb);
    }
}