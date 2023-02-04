#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MX = 16;

int n, mx, st;
int cost[MX + 2][MX + 2];
int cache[MX + 2][1 << MX];

int solve(int cur, int vis) {
  if(vis == mx) return cost[cur][st];
  int &ret = cache[cur][vis];
  if(ret != -1) return ret;

  ret = INF;
  for(int nxt = 0; nxt < n; nxt++) {
    int b = (1 << nxt);
    if(b & vis) continue;
    if(cost[cur][nxt] == INF) continue;
    int tmp = cost[cur][nxt] + solve(nxt, vis | b);
    ret = min(tmp, ret);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cost, 0x3f, sizeof(cost));

  cin >> n;
  mx = (1 << n) - 1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      int x; cin >> x;
      if(x == 0) continue;
      cost[i][j] = x;
    }
  
  int ans = INF;
  for(; st < n; st++) {
    memset(cache, -1, sizeof(cache));
    int res = solve(st, (1 << st));
    ans = min(ans, res);
  }
  cout << ans;
}