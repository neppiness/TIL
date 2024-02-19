import java.io.*;
import java.util.*;

public class Main {

    private static int n, m;
    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, -1, 0, 1};

    public static class Node {

        public int x;
        public int y;
        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

    private static boolean oob(int x, int y) {
        return x >= n || x < 0 || y >= m || y < 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        boolean[][] board = new boolean[n][m];
        boolean[][] isVisited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = (st.nextToken().equals("1"));
            }
        }

        int count = 0, maxSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!board[i][j] || isVisited[i][j]) {
                    continue;
                }
                isVisited[i][j] = true;
                count++;
                int size = 0;
                Queue<Node> q = new ArrayDeque<>();
                q.add(new Node(i, j));
                while (!q.isEmpty()) {
                    Node cur = q.poll();
                    size++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if (oob(nx, ny) || !board[nx][ny] || isVisited[nx][ny]) {
                            continue;
                        }
                        isVisited[nx][ny] = true;
                        q.add(new Node(nx, ny));
                    }
                }
                maxSize = Math.max(maxSize, size);
            }
        }
        System.out.println(count);
        System.out.print(maxSize);
    }

}

