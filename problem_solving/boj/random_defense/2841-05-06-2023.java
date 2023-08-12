import java.io.*;
import java.util.*;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, p, ans;
    static ArrayList<Stack<Integer>> stacks = new ArrayList<>();

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());

        // 6개의 줄
        for (int i = 0; i <= 6; i++)
            stacks.add(new Stack<>());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int lineNo = Integer.parseInt(st.nextToken());
            int frNo = Integer.parseInt(st.nextToken());

            Stack<Integer> stack = stacks.get(lineNo);
            while (!stack.isEmpty() && stack.peek() > frNo) {
                stack.pop(); ans++;
            }
            if (stack.isEmpty() || stack.peek() != frNo) {
                stack.add(frNo); ans++;
            }
        }
        System.out.println(ans);
    }
}