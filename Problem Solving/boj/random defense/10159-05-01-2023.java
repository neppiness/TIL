import java.io.*;
import java.util.*;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    // h_rel은 i번 노드 보다 무거운 노드의 집합.
    // l_rel은 i번 노드 보다 가벼운 노드의 집합.
    static HashMap<Integer, ArrayList<Integer>> h_rel = new HashMap<>();
    static HashMap<Integer, ArrayList<Integer>> l_rel = new HashMap<>();
    
    static int n, m;
    static int[] cnt;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        for (int i = 1; i <= n; i++) {
            h_rel.put(i, new ArrayList<>());
            l_rel.put(i, new ArrayList<>());
        }
        cnt = new int[n + 1];
        
        m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u, v;
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            h_rel.get(v).add(u);
            l_rel.get(u).add(v);
        }

        for (int i = 0)



    }

}