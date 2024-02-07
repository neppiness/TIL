import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class Main {

    static int[] dist = new int[20_002];
    static Node[] nodes = new Node[20_002];
    static PriorityQueue<CostAndDest> priorityQueue = new PriorityQueue<>();

    static class CostAndDest implements Comparable<CostAndDest> {
        int cost, dest;

        CostAndDest(int cost, int dest) {
            this.cost = cost;
            this.dest = dest;
        }

        @Override
        public int compareTo(CostAndDest rightHandSide) {
            return this.cost - rightHandSide.cost;
        }
    }

    static class Node {
        List<CostAndDest> adj = new ArrayList<>();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder stringBuilder = new StringBuilder();

        String line = bufferedReader.readLine();
        String[] splitLine = line.split(" ");
        int n = Integer.parseInt(splitLine[0]);
        int e = Integer.parseInt(splitLine[1]);

        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
            dist[i] = 0x7f7f7f7f;
        }

        line = bufferedReader.readLine();
        int st = Integer.parseInt(line);
        dist[st] = 0;

        while (e-- > 0) {
            line = bufferedReader.readLine();
            splitLine = line.split(" ");
            int u = Integer.parseInt(splitLine[0]);
            int v = Integer.parseInt(splitLine[1]);
            int w = Integer.parseInt(splitLine[2]);
            nodes[u].adj.add(new CostAndDest(w, v));
        }

        priorityQueue.add(new CostAndDest(0, st));
        while (!priorityQueue.isEmpty()) {
            CostAndDest cur = priorityQueue.poll();
            if (cur.cost != dist[cur.dest]) {
                continue;
            }
            for (CostAndDest nxt : nodes[cur.dest].adj) {
                int dCost = nxt.cost;
                int nextNode = nxt.dest;
                dCost += cur.cost;
                if (dCost >= dist[nextNode]) {
                    continue;
                }
                dist[nextNode] = dCost;
                priorityQueue.add(new CostAndDest(dCost, nextNode));
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dist[i] == 0x7f7f7f7f) {
                stringBuilder.append("INF");
            } else {
                stringBuilder.append(dist[i]);
            }
            stringBuilder.append('\n');
        }
        System.out.println(stringBuilder);
    }

}

