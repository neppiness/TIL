import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int n;
    static String input;

    static boolean isValid() {
        int nidx = 0;
        for (int idx = 0; idx < input.length(); idx = nidx) {
            if (input.charAt(idx) == '1') { // 확인하는 패턴의 첫 글자가 1인 경우
                if (idx + 3 >= input.length()) return false; // 최소 길이를 충족시키지 못하면 거짓 반환
                nidx = ++idx; // 1 다음 글자로 이동
                while (input.charAt(nidx) == '0')
                    if (++nidx == input.length()) return false;
                if (nidx - idx < 2) return false;
                idx = nidx;
                while (input.charAt(nidx) == '1')
                    if (++nidx == input.length()) break;
                int nnidx = input.indexOf("00", nidx);
                if (nnidx == -1) continue;
                if (nnidx == nidx) nidx--;
                if (nidx == idx) return false;
            } else { // 확인하는 패턴의 첫 글자가 0인 경우
                if (idx + 1 == input.length()) return false;
                if (input.charAt(idx + 1) != '1') return false;
                nidx = idx + 2;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            input = br.readLine();
            if (isValid()) sb.append("YES\n");
            else sb.append("NO\n");
        }
        System.out.print(sb);
    }
}