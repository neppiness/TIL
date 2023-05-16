import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static String input;

    static int getCode() {
        int lim = (input.length() - 1)/2;
        int idx = 0, revIdx = input.length() - 1;
        for (; idx <= lim; idx++, revIdx--)
            if (input.charAt(idx) != input.charAt(revIdx)) break;
        if (idx > lim) return 0;
        int nidx = idx + 1; int nrevIdx = revIdx;
        for (; nidx <= lim; nidx++, nrevIdx--)
            if (input.charAt(nidx) != input.charAt(nrevIdx)) break;
        if (nidx > lim) return 1;
        nidx = idx; nrevIdx = revIdx - 1;
        for (; nidx <= lim; nidx++, nrevIdx--)
            if (input.charAt(nidx) != input.charAt(nrevIdx)) break;
        if (nidx > lim) return 1;
        return 2;
    }

    public static void main(String[] args) throws IOException {

        int n = parseInt(br.readLine());
        while (n-- > 0) {
            input = br.readLine();
            sb.append(getCode()).append('\n');
        }
        System.out.print(sb);
    }
}