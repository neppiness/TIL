import java.io.*;
import java.math.BigInteger;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        String input = "";
        while ((input = br.readLine()) != null) {
            BigInteger x = new BigInteger(input);
            BigInteger mul = new BigInteger("1");
            int cnt = 1;
            while (!mul.mod(x).equals(BigInteger.valueOf(0))) {
                mul = mul.multiply(BigInteger.valueOf(10));
                mul = mul.add(BigInteger.ONE);
                cnt++;
            }
            sb.append(cnt).append('\n');
        }
        System.out.print(sb);
    }
}