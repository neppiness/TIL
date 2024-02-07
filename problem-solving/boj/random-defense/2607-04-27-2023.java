import java.io.*;

public class Main {

    public static int[] countChars(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            int idx = (int)c - 'A';
            cnt[idx]++;
        }
        return cnt;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        String s = br.readLine();
        int len = s.length();
        int[] wordComp = countChars(s);

        int cnt = 0;
        while (--n > 0) {
            s = br.readLine();
            int tmplen = s.length();
            int[] tmp = countChars(s);

            int totDiff = 0;
            for (int i = 0; i < 26; i++) {
                totDiff += Math.abs(wordComp[i] - tmp[i]);
            }
            if (tmplen == len && totDiff == 2) cnt++;
            else if (Math.abs(tmplen - len) == 1 && totDiff == 1) cnt++;
            else if (totDiff == 0) cnt++;
        }
        bw.write(String.valueOf(cnt));
        bw.flush();
    }
}