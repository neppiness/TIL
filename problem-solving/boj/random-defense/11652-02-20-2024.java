import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<Long, Integer> cards = new HashMap<>();

        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            long x = Long.parseLong(br.readLine());
            Integer countX = cards.get(x);
            if (countX == null) {
                cards.put(x, 1);
                maxCount = Math.max(maxCount, 1);
            } else {
                cards.put(x, countX + 1);
                maxCount = Math.max(maxCount, countX + 1);
            }
        }

        long ans = ((long)1 << 62);
        for (long key : cards.keySet()) {
            int count = cards.get(key);
            if (count == maxCount) {
                ans = Math.min(ans, key);
            }
        }
        System.out.print(ans);
    }

}

