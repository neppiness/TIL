import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int[] h;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        h = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++)
            h[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(h);
        int ansidx = n/2;
        if(n % 2 == 0) ansidx--;
        System.out.println(h[ansidx]);
    }
}