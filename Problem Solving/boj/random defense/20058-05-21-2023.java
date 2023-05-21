import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[][] ice = new int[66][66];
    static ArrayList<Integer> fs = new ArrayList<>();

    static int[] dx = new int[]{1, 0, -1, 0};
    static int[] dy = new int[]{0, 1, 0, -1};
    static boolean[][] vis;

    static int n, lg, q;

    static class Coord {
        int x, y;
        Coord(int x_, int y_) { this.x = x_; this.y = y_; }
        void visit() { vis[this.x][this.y] = true; }
        boolean isVisited() { return vis[this.x][this.y]; }
        boolean oob() { 
            return (this.x >= n || this.x < 0 || this.y >= n || this.y < 0);
        }
    }

    static void rotate(int f) {
        int unitSize = (1 << f);
        
    }

    static void adjCheckAndReduce() {
        int[][] adjCount = new int[n][n];
        for (int cx = 0; cx < n; cx++) {
            for (int cy = 0; cy < n; cy++) {
                for (int dir = 0; dir < 4; dir++) {
                    Coord nxt = new Coord(cx + dx[dir], cy + dy[dir]);
                    if (nxt.oob()) continue;
                    adjCount[cx][cy]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (adjCount[i][j] < 3) ice[i][j]--;
    }

    static void fireStorm(int f) {
        rotate(f);
        adjCheckAndReduce();
    }

    static int countBiggestMass(Coord start) {
        int count = 0;
        Queue<Coord> q = new ArrayDeque<>();
        q.add(start); start.visit();
        while (!q.isEmpty()) {
            Coord cur = q.poll();
            int cx = cur.x; int cy = cur.y;
            for (int dir = 0; dir < 4; dir++) {
                Coord nxt = new Coord(cx + dx[dir], cy + dy[dir]);
                if (nxt.oob() || nxt.isVisited()) continue;
                count++; q.add(nxt); nxt.visit();
            }
        }
        return count;
    }

    static int findBiggestMass() {
        vis = new boolean[n][n];
        int size = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) continue;
                size = Math.max(size, countBiggestMass(new Coord(i, j)));
            }
        return size;
    }

    static void printResult() {
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                sum += ice[i][j];
        System.out.println(sum);
        System.out.println(findBiggestMass());
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        lg = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        n = (1 << lg);

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine()); 
            for (int j = 0; j < n; j++)
                ice[i][j] = Integer.parseInt(st.nextToken());
        }
        
        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens())
            fs.add(Integer.parseInt(st.nextToken()));
        
        for (int f : fs) fireStorm(f);
        printResult();
    }
}