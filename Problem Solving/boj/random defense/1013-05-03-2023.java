import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static boolean solve() throws IOException {
        char[] pattern = br.readLine().toCharArray();

        for (int i = 0; i < pattern.length; i++) {
            if (pattern[i] == '0') { // 01 패턴 확인
                if (i + 1 == pattern.length || pattern[i + 1] != '1')
                    return false;
                i++;
            } else { // 100+1+ 패턴 확인
                if (i + 3 >= pattern.length) return false;
                if (pattern[i + 1] == '1' || pattern[i + 2] == '1' ) return false;
                i = i + 2;
                while (i + 1 < pattern.length && pattern[i + 1] == '0') i++;
                if (i == pattern.length) return false;
                while (i + 1 < pattern.length && pattern[i + 1] == '1') i++;
                if (pattern[i] == '0') {
                    if (i + 1 == pattern.length) return false;
                    else if (pattern[i + 1] == '0') { i -= 2; continue; }
                    else { i--; continue; }
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            if (solve()) sb.append("YES\n");
            else sb.append("NO\n");
        }
        System.out.println(sb);
    }
}
