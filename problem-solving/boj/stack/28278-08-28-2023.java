import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static Stack<Integer> stk = new Stack<>();

    private static void process() throws IOException {
        st = new StringTokenizer(br.readLine());
        int cmd = Integer.parseInt(st.nextToken());
        switch (cmd) {
            case 1:
                int x = Integer.parseInt(st.nextToken());
                stk.add(x);
                break;
            case 2:
                if (stk.isEmpty()) sb.append("-1\n");
                else sb.append(stk.pop()).append('\n');
                break;
            case 3:
                sb.append(stk.size()).append('\n');
                break;
            case 4:
                if (stk.isEmpty()) sb.append("1\n");
                else sb.append("0\n");
                break;
            default:
                if (stk.isEmpty()) sb.append("-1\n");
                else sb.append(stk.peek()).append('\n');
        }
    }

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) process();
        System.out.println(sb.toString());
    }
}

