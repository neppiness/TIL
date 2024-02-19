import java.io.*;
import java.util.*;

public class Main {

    static long solve(long a, long b, long c) {
        if (b == 1) {
            return a % c;
        }
        long tmp = solve(a, b / 2, c);
        if (b % 2 == 0) {
            return tmp * tmp % c;
        }
        return ((a * tmp) % c) * tmp % c;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        long c = Long.parseLong(st.nextToken());

        long ans = solve(a, b, c);
        System.out.print(ans);
    }

}

