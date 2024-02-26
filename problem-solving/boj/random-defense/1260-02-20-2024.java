import java.io.*;
import java.util.*;

public class Main {

    static List<Set<Integer>> adj = new ArrayList<>();
    static boolean[] isVisited = new boolean[1002];
    static StringBuilder sb = new StringBuilder();

    static void dfs(int cur) {
        sb.append(cur).append(' ');
        isVisited[cur] = true;
        for (int nxt : adj.get(cur)) {
            if (isVisited[nxt]) {
                continue;
            }
            dfs(nxt);
        }
    }

    static void bfs(int start) {
        Queue<Integer> q = new ArrayDeque<Integer>();
        q.add(start);
        isVisited[start] = true;
        while (!q.isEmpty()) {
            int cur = q.poll();
            sb.append(cur).append(' ');
            for (int nxt : adj.get(cur)) {
                if (isVisited[nxt]) {
                    continue;
                }
                isVisited[nxt] = true;
                q.add(nxt);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= n; i++) {
            adj.add(new TreeSet<>());
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        dfs(v);
        sb.append('\n');
        Arrays.fill(isVisited, false);
        bfs(v);
        System.out.print(sb);
    }

}


