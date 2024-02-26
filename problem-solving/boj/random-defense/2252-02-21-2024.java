import java.io.*;
import java.util.*;

public class Main {

    static int[] ind = new int[32_002];
    static List<List<Integer>> adj = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            ind[b]++;
            adj.get(a).add(b);
        }

        StringBuilder sb = new StringBuilder();
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            if (ind[i] > 0) {
                continue;
            }
            q.add(i);
        }
        while (!q.isEmpty()) {
            int cur = q.poll();
            sb.append(cur).append(' ');
            for (int nxt : adj.get(cur)) {
                ind[nxt]--;
                if (ind[nxt] == 0) {
                    q.add(nxt);
                }
            }
        }
        System.out.print(sb);
    }

}

