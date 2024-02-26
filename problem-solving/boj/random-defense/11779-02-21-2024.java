import java.io.*;
import java.util.*;

public class Main {

    static class Edge {

        public int v;
        public int cost;

        public Edge(int v, int cost) {
            this.v = v;
            this.cost = cost;
        }

    }

    static final int INF = 0x7f7f7f7f;
    static List<List<Edge>> adj = new ArrayList<>();
    static StringBuilder sb = new StringBuilder();
    static int[] dist = new int[1002];
    static int count = 0;
    static int start, end;

    static boolean dfs(int cur, int cost) {
        if (cur == end && dist[cur] == cost) {
            sb.append(cur).append(' ');
            count++;
            return true;
        }
        for (Edge curEdge : adj.get(cur)) {
            if (cost + curEdge.cost != dist[curEdge.v]) {
                continue;
            }
            if (dfs(curEdge.v, dist[curEdge.v])) {
                sb.append(cur).append(' ');
                count++;
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int co = Integer.parseInt(st.nextToken());
            adj.get(u).add(new Edge(v, co));
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        Arrays.fill(dist, INF);
        PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> o1.cost - o2.cost);
        dist[start] = 0;
        pq.add(new Edge(start, 0));
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            if (cur.cost != dist[cur.v]) {
                continue;
            }
            for (Edge e : adj.get(cur.v)) {
                int nxt = e.v;
                int nxtDist = dist[cur.v] + e.cost;
                if (nxtDist >= dist[nxt]) {
                    continue;
                }
                dist[nxt] = nxtDist;
                pq.add(new Edge(nxt, nxtDist));
            }
        }
        System.out.println(dist[end]);
        dfs(start, 0);
        System.out.println(count);
        sb.setLength(sb.length() - 1);
        sb.reverse();
        System.out.print(sb);
    }

}

