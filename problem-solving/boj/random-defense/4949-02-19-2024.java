import java.util.*;
import java.io.*;

public class Main {

    private static boolean solve(String input) {
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c == '(' || c == '[') {
                stk.add(c);
            } else if (c == ']') {
                if (stk.isEmpty() || stk.peek() == '(') {
                    return false;
                } else {
                    stk.pop();
                }
            } else if (c == ')') {
                if (stk.isEmpty() || stk.peek() == '[') {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        return stk.size() == 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            String input = br.readLine();
            if (input.equals(".")) {
                System.out.print(sb);
                return;
            }
            boolean isValid = solve(input);
            if (isValid) {
                sb.append("yes\n");
            } else {
                sb.append("no\n");
            }
        }
    }

}


