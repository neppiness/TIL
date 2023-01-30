#include <bits/stdc++.h>
using namespace std;

const int MX = (1 << 20) - 1;
const int INF = 0x7f7f7f7f;

int mx, n;
int cost[22][22], cache[MX + 2];

void solve(int cur, int i) {
  if(i == n) return;
  for(int j = 0; j < n; j++) {
    int x = (1 << j);
    if(!(cur & x)) continue; // 해당 비트가 꺼져있다면 continue
    int prv = (cur & ~x);
    cache[cur] = min(cache[cur], cache[prv] + cost[i][j]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << __builtin_popcount(MX);

  // memset(cache, 0x7f, sizeof(cache));
  // cache[0] = 0;

  // cin >> n;
  // mx = (1 << n) - 1;

  // for(int i = 0; i < n; i++)
  //   for(int j = 0; j < n; j++)
  //     cin >> cost[i][j];

  // solve(0, 0);
  // cout << cache[mx];
}