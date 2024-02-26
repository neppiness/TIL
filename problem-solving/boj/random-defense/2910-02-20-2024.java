import java.io.*;
import java.util.*;

public class Main {

    static class Count implements Comparable<Count> {

        public int index;
        public int value;
        public int freq;

        public Count(int index, int value, int freq) {
            this.index = index;
            this.value = value;
            this.freq = freq;
        }

        @Override
        public int compareTo(Count rightTerm) {
            if (this.freq == rightTerm.freq) {
                return this.index - rightTerm.index;
            }
            return rightTerm.freq - this.freq;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        ArrayList<Count> counts = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());
            Count foundCount = null;
            for (Count count : counts) {
                if (x == count.value) {
                    foundCount = count;
                    break;
                }
            }
            if (foundCount == null) {
                counts.add(new Count(i, x, 1));
            } else {
                foundCount.freq++;
            }
        }
        Collections.sort(counts);

        StringBuilder sb = new StringBuilder();
        for (Count count : counts) {
            for (int i = 0; i < count.freq; i++) {
                sb.append(count.value).append(' ');
            }
        }
        System.out.print(sb);
    }

}

