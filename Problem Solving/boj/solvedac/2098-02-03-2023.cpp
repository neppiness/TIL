#include <bits/stdc++.h>
using namespace std;

const int MX = 16;
const int INF = 0x3f3f3f3f;

int cost[MX + 2][MX + 2];
int cache[MX + 2][(1 << MX)]; // cache[cur][vis_status] = min_cost

int n, mx, init;

int solve(int cur, int st) { // cur: current city, vis: visited cities
  if(st == mx) return cost[cur][init];
  int &ret = cache[cur][st];
  if(ret != INF) return ret;

  for(int nxt = 0; nxt < n; nxt++) {
    int b = (1 << nxt);
    if(st & b) continue;
    int tmp = cost[cur][nxt] + solve(nxt, st | b);
    ret = min(ret, tmp);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cost, 0x3f, sizeof(cost));
  memset(cache, 0x3f, sizeof(cache));

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      int x; cin >> x;
      if(!x) continue;
      cost[i][j] = x;
    }

  mx = (1 << n) - 1;
  int ans = INF;
  for(; init < n; init++)
    ans = min(solve(init, (1 << init)), ans);

  cout << ans;
}