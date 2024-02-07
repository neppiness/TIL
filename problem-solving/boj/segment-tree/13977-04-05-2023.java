import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    private static final BigInteger MOD =  new BigInteger("1000000007");
    private static final int MX = 4_000_000;
    private static final int ROOT = 1;
    private static BigInteger[] muls = new BigInteger[MX * 4];

    static int i, j;

    public static BigInteger init(int st, int en, int cur) {
        if(st == en) return muls[cur] = BigInteger.valueOf(st);
        int mid = (st + en) / 2;
        BigInteger lt = init(st, mid, cur * 2);
        BigInteger rt = init(mid + 1, en, cur * 2 + 1);
        return muls[cur] = lt.multiply(rt);
    }

    public static BigInteger mul(int st, int en, int cur) {
        if(en < i || st > j) return BigInteger.valueOf(1);
        if(i <= st && en <= j) return muls[cur];

        int mid = (st + en) / 2;
        BigInteger lt = mul(st, mid, cur * 2);
        BigInteger rt = mul(mid + 1, en, cur * 2 + 1);
        return lt.multiply(rt);
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        init(0, MX, ROOT);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        while(m-- != 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());

            i = 1; j = r;
            BigInteger rFact = mul(0, MX, ROOT);
            i = n - r + 1; j = n;
            BigInteger nPr = mul(0, MX, ROOT);
            BigInteger ans = nPr.divide(rFact).mod(MOD);

            bw.write(ans.toString());
            bw.newLine();
        }
        bw.flush();
    }
}