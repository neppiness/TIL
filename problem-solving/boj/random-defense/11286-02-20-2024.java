import java.io.*;
import java.util.*;

public class Main {

    static class Value implements Comparable<Value> {

        public int value;

        public Value(int value) {
            this.value = value;
        }

        @Override
        public int compareTo(Value rightTerm) {
            int absDiff = Math.abs(this.value) - Math.abs(rightTerm.value);
            if (absDiff == 0) {
                return this.value - rightTerm.value;
            }
            return absDiff;
        }

    }

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        PriorityQueue<Value> pq = new PriorityQueue<>();
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int x = Integer.parseInt(br.readLine());
            if (x == 0) {
                if (pq.isEmpty()) {
                    sb.append(0).append('\n');
                } else {
                    sb.append(pq.poll().value).append('\n');
                }
            } else {
                pq.add(new Value(x));
            }
        }
        System.out.print(sb);
    }

}

