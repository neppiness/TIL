import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        Long sum = 0L;
        for (int i = 1; i <= n; i++)
            sum += (long)(n/i)*i;
        System.out.println(sum);
    }
}