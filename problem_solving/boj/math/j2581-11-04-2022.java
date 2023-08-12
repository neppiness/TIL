import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static boolean[] pr = new boolean[10002];
    public static void prCheck() {
        pr[1] = false;
        int n;
        for (int i = 2; i <= 10000; i++) pr[i] = true;
        for (int i = 2; i <= 10000; i++) {
            if (!pr[i]) continue;
            n = 2;
            while (i*n <= 10000) pr[i*(n++)] = false;
        }
        return;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int st = Integer.parseInt(br.readLine());
        int en = Integer.parseInt(br.readLine());

        prCheck();

        int minPr = 0x7f7f7f7f, sum = 0;
        for (int i = st; i <= en; i++) {
            if (!pr[i]) continue;
            sum += i;
            minPr = Math.min(i, minPr);
        }
        if(minPr == 0x7f7f7f7f) {
            bw.write("-1");
            bw.flush();
            return;
        }
        bw.write(String.valueOf(sum));
        bw.newLine();
        bw.write(String.valueOf(minPr));
        bw.flush();
    }
}
