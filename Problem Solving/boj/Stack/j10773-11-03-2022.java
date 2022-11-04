import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        Stack<Integer> st = new Stack<>();
        int x;
        for(int i = 0; i < n; i++) {
            x = Integer.parseInt(br.readLine());
            if(x == 0) st.pop();
            else st.push(x);
        }
        int res = 0;
        while(!st.empty()) {
            res += st.peek();
            st.pop();
        }
        bw.write(String.valueOf(res));
        bw.flush();
    }
}