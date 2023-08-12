import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static BigInteger[] p = new BigInteger[252];

    private static BigInteger solve(int x) {
        BigInteger ret = p[x];
        if (!ret.equals(BigInteger.valueOf(-1))) return ret;
        ret = solve(x - 1).add(solve(x - 2).multiply(BigInteger.valueOf(2)));
        p[x] = ret;
        return ret;
    }

    public static void main(String[] args) throws IOException {
        Arrays.fill(p, BigInteger.valueOf(-1));
        p[0] = BigInteger.valueOf(1);
        p[1] = BigInteger.valueOf(1);

        String input = "";
        while((input=br.readLine())!=null) {
            int x = Integer.parseInt(input);
            sb.append(solve(x)).append('\n');
        }
        System.out.print(sb);
    }
}