import java.io.*import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] no = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            no[i] = Integer.parseInt(st.nextToken());
        }
        int x = Integer.parseInt(br.readLine());
        Arrays.sort(no);
        int end = n - 1;
        int ans = 0;
        for (int start = 0; start < n; start++) {
            while (no[start] + no[end] > x && start < end) {
                end--;
            }
            if (start == end) break;
            if (no[start] + no[end] == x) {
                ans++;
            }
        }
        System.out.print(ans);
    }

}


