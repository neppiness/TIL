import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = 5;
        int a = 0;
        while(n-- > 0) a += Integer.parseInt(br.readLine());
        bw.write(String.valueOf(a));
        bw.flush();
    }
}