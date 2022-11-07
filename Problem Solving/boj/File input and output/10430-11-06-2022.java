import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int res1 = (a+b)%c;
        int res2 = (a*b)%c;
        
        bw.write(String.valueOf(res1));
        bw.newLine();
        bw.write(String.valueOf(res1));
        bw.newLine();
        bw.write(String.valueOf(res2));
        bw.newLine();
        bw.write(String.valueOf(res2));
        bw.flush();
    }
}