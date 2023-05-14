import java.io.*;
import java.util.*;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int n;

    static boolean isValid() {
        for (int len = 1; len <= sb.length()/2; len++) {
            String a = sb.substring(sb.length() - len, sb.length());
            String b = sb.substring(sb.length() - len * 2, sb.length() - len);
            if (a.equals(b)) return false;
        }
        return true;
    }

    static boolean solve(int len) {
        if (len == n) return true;

        for (char c = '1'; c <= '3'; c++) {
            sb.append(c);
            if (isValid() && solve(len + 1))
                return true;
            sb.deleteCharAt(sb.length() - 1);
        }
        return false;
    }

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        solve(0);
        System.out.println(sb);
    }
}