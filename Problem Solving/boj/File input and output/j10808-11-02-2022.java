import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;

public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = new String(br.readLine());
        int[] a = new int[26];
        for(int i = 0; i < str.length(); i++)
            a[(int)(str.charAt(i) - 'a')]++;
        for(int i = 0; i < 26; i++) {
            bw.write(String.valueOf(a[i]));
            bw.write(' ');
        }
        bw.flush();
    }
}