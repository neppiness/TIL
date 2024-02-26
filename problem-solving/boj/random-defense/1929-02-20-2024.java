import java.io.*;
import java.util.*;

public class Main {

    static final int MX = 1_000_000;
    static boolean[] isPrime = new boolean[MX + 1];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        Arrays.fill(isPrime, true);
        isPrime[1] = false;

        List<Integer> primes = new ArrayList<>();
        for (int p = 2; p <= MX; p++) {
            if (isPrime[p]) {
                primes.add(p);
            }
            for (long k = p; k * p <= MX; k++) {
                isPrime[(int) (k * p)] = false;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int p : primes) {
            if (p < m || p > n) {
                continue;
            }
            sb.append(p).append('\n');
        }
        System.out.print(sb);
    }

}

