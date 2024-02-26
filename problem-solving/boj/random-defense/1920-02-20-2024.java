import java.io.*;
import java.util.*;

public class Main {

    static int[] a;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(a);

        int t = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < t; i++) {
            int x = Integer.parseInt(st.nextToken());
            int foundIndex = Arrays.binarySearch(a, x);
            if (foundIndex >= 0) {
                sb.append(1);
            } else {
                sb.append(0);
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }

}

