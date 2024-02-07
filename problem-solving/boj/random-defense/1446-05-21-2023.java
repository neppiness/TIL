import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, d;
    static List<List<Edge>> adj = new ArrayList<>();

    static int[] dist;

    static class Status implements Comparable<Status> {

        int v, cost;
        Status(int v_, int cost_) {
            this.v = v_; this.cost = cost_;
        }

        @Override
        public int compareTo(Status rt) {
            if (this.cost == rt.cost)
                return this.v - rt.v;
            return this.cost - rt.cost;
        }
    }

    static class Edge {
        int v, cost;
        Edge(int v_, int cost_) {
            this.v = v_; this.cost = cost_;
        }
    }

    public static void main(String[] args) throws IOException {
    
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        dist = new int[d + 1];
        Arrays.fill(dist, 0x7f7f7f7f);

        for (int i = 0; i < d; i++) {
            List<Edge> curAdj = new ArrayList<>();
            curAdj.add(new Edge(i + 1, 1));
            adj.add(curAdj);
        }

        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int co = Integer.parseInt(st.nextToken());
            if (v > d) continue;
            adj.get(u).add(new Edge(v, co));
        }

        PriorityQueue<Status> pq = new PriorityQueue<>();
        pq.add(new Status(0, 0));
        dist[0] = 0;
        while (!pq.isEmpty()) {
            Status cur = pq.poll();
            int u = cur.v; int co = cur.cost;
            if (co != dist[u]) continue;
            for (Edge nxt : adj.get(u)) {
                int v = nxt.v;
                int dco = co + nxt.cost;
                if (v > d) continue;
                if (dist[v] < dco) continue;
                dist[v] = dco;
                if (v < d) pq.add(new Status(v, dco));
            }
        } 
        System.out.print(dist[d]); 
    }
}