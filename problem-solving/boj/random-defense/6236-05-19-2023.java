import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int days, drawLimit;
    static int[] money = new int[100_002];

    static boolean solve(int drawMoney) {
        int drawCount = 1;
        int onHand = drawMoney;

        for (int i = 0; i < days; i++) {
            if (money[i] > drawMoney) return false;
            if (money[i] > onHand) {
                onHand = drawMoney;
                drawCount++;
            }
            onHand -= money[i];
        }
        return drawCount <= drawLimit;
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        days = Integer.parseInt(st.nextToken());
        drawLimit = Integer.parseInt(st.nextToken());

        for (int i = 0; i < days; i++)
            money[i] = Integer.parseInt(br.readLine());

        int start = 0, end = 0x3f3f3f3f;
        while (start < end) {
            int mid = (start + end) / 2;
            if (solve(mid)) end = mid;
            else start = mid + 1;
        }
        System.out.print(start);
    }
}