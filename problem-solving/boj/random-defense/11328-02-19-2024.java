import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] cnt = new int[26];
            String s = st.nextToken();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                cnt[c - 'a']++;
            }
            s = st.nextToken();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                cnt[c - 'a']--;
            }
            boolean isPossible = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] != 0) isPossible = false;
            }
            if (isPossible) {
                sb.append("Possible").append('\n');
            } else {
                sb.append("Impossible").append('\n');
            }
        }
        System.out.print(sb);
    }

}

