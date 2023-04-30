import java.io.*;
import java.util.*;

public class Main {

    static String s;
    static StringBuilder t;

    static boolean solve() {
        while (t.length() != 0) {
            int lastIdx = t.length() - 1;
            if (t.charAt(lastIdx) == 'A') {
                t.deleteCharAt(lastIdx);
            } else {
                t.deleteCharAt(lastIdx);
                t.reverse();
            }
            if (t.toString().equals(s)) return true;
        }
        return false;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        s = br.readLine();
        t = new StringBuilder(br.readLine());

        if (solve()) bw.write(String.valueOf(1));
        else bw.write(String.valueOf(0));
        bw.flush();
    }
}