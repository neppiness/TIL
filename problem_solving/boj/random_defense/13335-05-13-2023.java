import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, len, w;
    static int curW, time;
    
    static Truck[] tr;
    static int onBridgeIdx, waitingIdx; // onBridgeIdx <= waitingIdx

    static class Truck {
        public int weight, position = 0;

        public void move() {
            if (position == 0) {
                curW += this.weight;
            }
            position++;
            if (position > len) {
                curW -= this.weight;
                onBridgeIdx++;
            }
        }

        Truck(int w_) { this.weight = w_; }
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = parseInt(st.nextToken());
        len = parseInt(st.nextToken());
        w = parseInt(st.nextToken());

        tr = new Truck[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            tr[i] = new Truck(parseInt(st.nextToken()));

        while (onBridgeIdx < n) {
            time++;
            for (int i = onBridgeIdx; i < waitingIdx; i++)
                tr[i].move();
            if (waitingIdx == n) continue;
            if (w < curW + tr[waitingIdx].weight) continue;
            tr[waitingIdx++].move();
        }
        System.out.print(time);
    }
}