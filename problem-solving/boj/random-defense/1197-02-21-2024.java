import java.io.*;
import java.util.*;

public class Main {

    static int[] p = new int[10_002];

    static class Edge {

        int a;
        int b;
        int c;

        public Edge(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

    }

    static int find(int x) {
        if (p[x] < 0) {
            return x;
        }
        return p[x] = find(p[x]);
    }

    static boolean hasSameParent(int a, int b) {
        a = find(a);
        b = find(b);
        return a == b;
    }

    static void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (p[a] > p[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        p[a] += p[b];
        p[b] = a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        Arrays.fill(p, -1);

        PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> o1.c - o2.c);
        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            pq.add(new Edge(a, b, c));
        }

        int ans = 0;
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            if (hasSameParent(cur.a, cur.b)) {
                continue;
            }
            merge(cur.a, cur.b);
            ans += cur.c;
        }
        System.out.print(ans);
    }

}

