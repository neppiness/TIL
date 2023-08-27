import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static ArrayList<Edge> edges = new ArrayList<>();
    static int[] p = new int[10_002];

    static int find(int cur) {
        if (p[cur] < 0) return cur;
        p[cur] = find(p[cur]);
        return p[cur];
    }

    static boolean tryToMerge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (p[u] > p[v]) {
            int tmp = u;
            u = v;
            v = tmp;
        }
        p[u] += p[v];
        p[v] = u;
        return true;
    }

    static class Edge implements Comparable<Edge> {

        int cost, cur, nxt;

        Edge(int cost, int cur, int nxt) {
            this.cost = cost;
            this.cur = cur;
            this.nxt = nxt;
        }

        @Override
        public int compareTo(Edge rhs) {
            return this.cost - rhs.cost;
        }
    }

    public static void main(String[] args) throws IOException {

        Arrays.fill(p, -1);

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        while (e-- > 0) {
            st = new StringTokenizer(br.readLine());
            int cur = Integer.parseInt(st.nextToken());
            int nxt = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            Edge edge = new Edge(cost, cur, nxt);
            edges.add(edge);
        }
        Collections.sort(edges);

        int totalCost = 0;
        for (int index = 0; index < edges.size(); index++) {
            Edge edge = edges.get(index);
            int u = edge.cur;
            int v = edge.nxt;
            int co = edge.cost;
            if (tryToMerge(u, v)) totalCost += co;
        }
        System.out.println(totalCost);
    }
}

