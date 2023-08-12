import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static class CostAndEndPoint implements Comparable<CostAndEndPoint> {
        
        public int cost, v;

        CostAndEndPoint(int cost_, int v_) {
            this.cost = cost_; this.v = v_;
        }
        
        @Override
        public int compareTo(CostAndEndPoint rt) {
            if (this.cost == rt.cost) {
                return this.v - rt.v;
            }
            return rt.cost - this.cost;
        }
    }

    static boolean ans = false;
    static int n, m;
    static int[] dist;
    static HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>();

    static void solve(int start) {
        PriorityQueue<CostAndEndPoint> pq = new PriorityQueue<>();
        Arrays.fill(dist, 0);
        dist[start] = 1;
        pq.add(new CostAndEndPoint(1, start));

        while (!pq.isEmpty()) {
            CostAndEndPoint curCAEP = pq.poll();
            int cur = curCAEP.v; int co = curCAEP.cost;
            if (dist[cur] >= 5) { ans = true; return; } 
            if (dist[cur] != co) continue;
            ArrayList<Integer> edges = adj.get(cur);
            for (int nxt : edges) {
                int nco = dist[cur] + 1;
                if (nco < dist[nxt]) continue;
                dist[nxt] = nco;
                pq.add(new CostAndEndPoint(nco, nxt));
            }
        }
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        dist = new int[n];

        for (int i = 0; i < n; i++)
            adj.put(i, new ArrayList<>());

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj.get(u).add(v); adj.get(v).add(u);
        }

        for (int i = 0; i < n; i++) solve(i);

        if (ans) System.out.print(1);
        else System.out.print(0);
    }
}