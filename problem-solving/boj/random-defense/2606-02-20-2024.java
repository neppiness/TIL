import java.io.*;
import java.util.*;

public class Main {

  static List<List<Integer>> adj = new ArrayList<>();
  static int count = 0;
  static boolean[] isVisited = new boolean[102];

  static void dfs(int cur) {
    isVisited[cur] = true;
    count++;
    for (int nxt : adj.get(cur)) {
      if (isVisited[nxt]) {
        continue;
      }
      dfs(nxt);
    }
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
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      adj.get(a).add(b);
      adj.get(b).add(a);
    }
    
    dfs(1);
    System.out.print(count - 1);
  }

}
