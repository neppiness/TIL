import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ArrayList<Integer> arr = new ArrayList<>();
        int a;
        for(int i = 0; i < 3; i++) {
            a = Integer.parseInt(st.nextToken());
            arr.add(a);
        }
        Collections.sort(arr);
        bw.write(String.valueOf(arr.get(1)));
        bw.flush();
    }
}