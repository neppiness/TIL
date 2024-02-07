import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String jh = br.readLine();
        String dr = br.readLine();
        if(jh.length() < dr.length()) bw.write("no");
        else bw.write("go");
        bw.flush();
    }
}