import java.io.*;
import java.util.*;

public class Main {

  static int[] dp = new int[11];

  static int solve(int x) {
    if (x < 0) {
      return 0;
    }
    if (dp[x] != -1) {
      return dp[x];
    }
    dp[x] = solve(x - 1) + solve(x - 2) + solve(x - 3);
    return dp[x];
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(br.readLine());
    Arrays.fill(dp, -1);
    dp[0] = 1;

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < t; i++) {
      int n = Integer.parseInt(br.readLine());
      sb.append(solve(n)).append('\n');
    }
  }

}
