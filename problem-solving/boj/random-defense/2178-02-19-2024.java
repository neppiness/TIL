import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static boolean[][] board;
    static int[][] dist;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static class Node {
      public int x;
      public int y;
      public Node(int x, int y) {
        this.x = x;
        this.y = y;
      }
    }

    static boolean oob(int x, int y) {
      return x >= n || x < 0 || y >= m || y < 0;
    } 

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        board = new boolean[n][m];
        dist = new int[n][m];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], -1);
        }

        for (int i = 0; i < n; i++) {
            String row = br.readLine();
            for (int j = 0; j < m; j++) {
                board[i][j] = (row.charAt(j) == '1');
            }
        }
      
        Queue<Node> q = new ArrayDeque<>();
        q.add(new Node(0, 0));
        dist[0][0] = 0;
        while (!q.empty()) {
          Node cur = q.poll();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (oob(nx, ny) || !board[nx][ny] || dist[nx][ny] != -1) {
              continue;
            }
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            q.add(new Node(nx, ny));
          }
        }
        System.out.print(dist[n - 1][m - 1]);
   }

}

