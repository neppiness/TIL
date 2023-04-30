import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        char[] no = br.readLine().toCharArray();

        int start = 0, end = 0;
        char mxChar;
        while (k > 0) {
            mxChar = no[start];
            int cycleNo = k;
            int tmp = start;
            while (cycleNo-- > 0) {
                if (no[tmp] > mxChar) {
                    end = tmp;
                    mxChar = no[tmp];
                }
                tmp++;
            }
            k -= (end - start);
            bw.write(mxChar);
            start = end + 1;
        }
        bw.flush();
    }
}