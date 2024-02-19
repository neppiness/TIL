import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        int[] ans = new int[26];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            c -= 'a';
            ans[c]++;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            sb.append(ans[i]).append(' ');
        }
        System.out.print(sb);
    }

}

