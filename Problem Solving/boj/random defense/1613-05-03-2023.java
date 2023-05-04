import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int n, k, s;

    static HashMap<Integer, ArrayList<Integer>> next_rel = new HashMap<>();
    static HashMap<Integer, ArrayList<Integer>> prev_rel = new HashMap<>();

    static boolean find(int st, int tar, HashMap<Integer, ArrayList<Integer>> adj) {
        Queue<Integer> q = new ArrayDeque<>();
        boolean[] vis = new boolean[n + 1];
        
        vis[st] = true;
        q.add(st);
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int nxt : adj.get(cur)) {
                if (vis[nxt]) continue;
                if (nxt == tar) return true;
                vis[nxt] = true;
                q.add(nxt);
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            next_rel.put(i, new ArrayList<>());
            prev_rel.put(i, new ArrayList<>());
        }

        while (k-- > 0) {
            // u가 v보다 먼저 일어났음
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            prev_rel.get(v).add(u); // v 사건 전에 u가 일어났음
            next_rel.get(u).add(v); // u 사건 후에 v가 일어났음
        }

        s = Integer.parseInt(br.readLine());
        while (s-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            if (find(u, v, prev_rel)) sb.append(1);
            else if (find(u, v, next_rel)) sb.append(-1);
            else sb.append(0);
            sb.append('\n');
        }
        System.out.print(sb);
    }
}