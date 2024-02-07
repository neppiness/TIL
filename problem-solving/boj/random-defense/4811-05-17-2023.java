import java.io.*;
import java.util.*;
import static java.lang.Integer.parseInt;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static long[][] cache = new long[32][32];

    static long solve(int w, int h) {
        if (w == 0 && h == 0) return 1;
        if (cache[w][h] != -1) return cache[w][h];

        long ret = 0L;
        if (w != 0) ret += solve(w - 1, h + 1);
        if (h != 0) ret += solve(w, h - 1);
        cache[w][h] = ret;
        return ret;
    }

    public static void main(String[] args) throws IOException {

        for (int i = 0; i <= 30; i++)
            Arrays.fill(cache[i], -1);
        cache[0][0] = 1;

        int x = parseInt(br.readLine());
        do {
            sb.append(solve(x, 0)).append('\n');
            x = parseInt(br.readLine());
        } while (x != 0);
        System.out.println(sb);
    }
}