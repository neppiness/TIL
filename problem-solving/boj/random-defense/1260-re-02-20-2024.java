import java.io.*;
import java.util.*;

public class Main {

    static Node[] nodes = new Node[1002];
    static boolean[] isVisited = new boolean[1002];
    static StringBuilder sb = new StringBuilder();

    static class Node {
        public Set<Integer> adj;
        public Node() {
            this.adj = new TreeSet<>();
        }
    }

    static void dfs(int cur) {
      isVisited[cur] = true;
      sb.append(cur).append(' ');
      for (int nxt : nodes[cur].adj) {
        if (isVisited[nxt]) {
          continue;
        }
        dfs(nxt);
      }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            nodes[a].adj.add(b);
            nodes[b].adj.add(a);
        }
        dfs(v);
        System.out.print(sb);
    }

}

