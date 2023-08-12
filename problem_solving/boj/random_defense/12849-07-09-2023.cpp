#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MOD = 1e9 + 7;

vector<int> adj[10];
int dp[10][100'002];

int solve(int cur, int d) {
  if (d == 0) return (cur == ROOT);
  int &ret = dp[cur][d];
  if (ret != -1) return ret;
  ret = 0;
  for (int nxt : adj[cur]) {
    ret += solve(nxt, d - 1);
    if (ret >= MOD) ret -= MOD;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  adj[1].push_back(2);
  adj[2].push_back(1);

  adj[1].push_back(3);
  adj[3].push_back(1);

  adj[2].push_back(3);
  adj[3].push_back(2);

  adj[4].push_back(2);
  adj[2].push_back(4);

  adj[3].push_back(4);
  adj[4].push_back(3);

  adj[3].push_back(5);
  adj[5].push_back(3);

  adj[4].push_back(5);
  adj[5].push_back(4);

  adj[4].push_back(6);
  adj[6].push_back(4);

  adj[6].push_back(5);
  adj[5].push_back(6);

  adj[6].push_back(7);
  adj[7].push_back(6);

  adj[7].push_back(8);
  adj[8].push_back(7);

  adj[5].push_back(8);
  adj[8].push_back(5);

  int d; cin >> d;
  cout << solve(ROOT, d);
}