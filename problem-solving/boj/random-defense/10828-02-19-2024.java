import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Stack<String> stk = new Stack<>();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();
            if (command.equals("push")) {
                stk.add(st.nextToken());
            } else if (command.equals("pop")) {
                if (stk.isEmpty()) {
                    sb.append(-1).append('\n');
                } else {
                    sb.append(stk.pop()).append('\n');
                }
            } else if (command.equals("size")) {
                sb.append(stk.size()).append('\n');
            } else if (command.equals("empty")) {
                if (stk.isEmpty()) {
                    sb.append(1).append('\n');
                } else {
                    sb.append(0).append('\n');
                }
            } else {
                if (stk.isEmpty()) {
                    sb.append(-1).append('\n');
                } else {
                    sb.append(stk.peek()).append('\n');
                }
            }
        }
        System.out.print(sb);
    }

}

