import java.io.*;
import java.util.*;

public class Main {

    static StringBuilder sb = new StringBuilder();
    static int[] lc = new int[26];
    static int[] rc = new int[26];

    static void dfs(int cur, int mode) { // 0: 전위, 1: 중위, 2: 후위
        if (mode == 0) {
            sb.append((char)(cur + 'A'));
        }
        if (lc[cur] != -1) {
            dfs(lc[cur], mode);
        }
        if (mode == 1) {
            sb.append((char)(cur + 'A'));
        }
        if (rc[cur] != -1) {
            dfs(rc[cur], mode);
        }
        if (mode == 2) {
            sb.append((char)(cur + 'A'));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Arrays.fill(lc, -1);
        Arrays.fill(rc, -1);

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int cur = (st.nextToken()).charAt(0) - 'A';
            char leftChildAsChar = st.nextToken().charAt(0);
            if (leftChildAsChar != '.') {
                int leftChild = leftChildAsChar - 'A';
                lc[cur] = leftChild;
            }
            char rightChildAsChar = st.nextToken().charAt(0);
            if (rightChildAsChar != '.') {
                int rightChild = rightChildAsChar - 'A';
                rc[cur] = rightChild;
            }
        }
        dfs(0, 0);
        sb.append('\n');
        dfs(0, 1);
        sb.append('\n');
        dfs(0, 2);
        System.out.print(sb);
    }

}

