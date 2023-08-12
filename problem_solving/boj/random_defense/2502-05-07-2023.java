import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final long MX = 100_000L;
    static long[] riceCake = new long[31];
    static int day;
    static long totalRiceCake;

    static boolean solve(long a) {
        riceCake[1] = a;
        long start = a, end = MX;
        while (start < end) {
            long mid = (start + end) / 2;
            riceCake[2] = mid;

            for (int i = 3; i <= day; i++)
                riceCake[i] = riceCake[i - 1] + riceCake[i - 2];

            if (riceCake[day] < totalRiceCake) start = mid + 1;
            else end = mid;
        }

        riceCake[2] = start;
        for (int i = 3; i <= day; i++)
            riceCake[i] = riceCake[i - 1] + riceCake[i - 2];
        return (riceCake[day] == totalRiceCake);
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        day = Integer.parseInt(st.nextToken());
        totalRiceCake = Long.parseLong(st.nextToken());

        for (long a = 1L; a <= MX; a++) {
            if (!solve(a)) continue;
            sb.append(a).append('\n').append(riceCake[2]);
            System.out.print(sb);
            return;
        }
    }
}