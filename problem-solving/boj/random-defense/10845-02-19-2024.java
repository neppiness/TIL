import java.io.*;
import java.util.*;

public class Main {

    private static final StringBuilder sb = new StringBuilder();
    private static final Deque<String> dq = new ArrayDeque<>();

    private static void push(String s) {
        dq.addLast(s);
    }

    private static void pop() {
        if (dq.isEmpty()) {
            sb.append(-1).append('\n');
        } else {
            sb.append(dq.pollFirst()).append('\n');
        }
    }

    private static void empty() {
        if (dq.isEmpty()) {
            sb.append(1).append('\n');
        } else {
            sb.append(0).append('\n');
        }
    }

    private static void front() {
        if (dq.isEmpty()) {
            sb.append(-1).append('\n');
        } else {
            sb.append(dq.peekFirst()).append('\n');
        }
    }

    private static void back() {
        if (dq.isEmpty()) {
            sb.append(-1).append('\n');
        } else {
            sb.append(dq.peekLast()).append('\n');
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            if (command.equals("push")) {
                push(st.nextToken());
            } else if (command.equals("pop")) {
                pop();
            } else if (command.equals("size")) {
                sb.append(dq.size()).append('\n');
            } else if (command.equals("empty")) {
                empty();
            } else if (command.equals("front")) {
                front();
            } else { // back
                back();
            }
        }
        System.out.print(sb);
    }

}

