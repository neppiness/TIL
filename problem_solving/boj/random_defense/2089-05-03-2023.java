import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());

        while (n != 0) {
            int x = n % -2;
            if (x == -1) sb.append("11");
            else if (x == 0) sb.append("0");
            else sb.append("1");
            n /= -2;
        }
        System.out.println(sb.reverse());
    }
}