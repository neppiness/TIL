import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    PriorityQueue<Integer> pq = new PriorityQueue<>();

    int t = Integer.parseInt(br.readLine());
    for (int i = 0; i < t; i++) {
      int x = Integer.parseInt(br.readLine());
      if (x == 0) {
        sb.append(pq.poll()).append('\n');
      } else {
        pq.add(x);
      }
    }
    System.out.print(sb);
  }

}
