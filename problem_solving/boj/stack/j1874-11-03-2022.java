import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.util.Stack;
import java.util.ArrayList;

public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Integer> st = new Stack<>();
        ArrayList<Character> ans = new ArrayList<>();

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[100002];
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(br.readLine());

        int j = 0;
        for(int i = 1; i <= n; i++) {
            st.push(i);
            ans.add('+');
            while(!st.empty() && arr[j] == st.peek()) {
                st.pop();
                ans.add('-');
                j++;
            }
        }
        if(!st.empty()) bw.write("NO");
        else {
            for(char a : ans) {
                bw.write(a);
                bw.newLine();
            }
        }
        bw.flush();
    }
}