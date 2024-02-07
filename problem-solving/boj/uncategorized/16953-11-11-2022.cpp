#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 0x7f7f7f7f;

int st, en;
int ans = INF;

void solve(ll cur, int cnt) {
  if(cur == en) ans = min(ans, cnt);
  if(cur >= en) return;
  solve(cur*10 + 1, cnt + 1);
  solve(cur*2, cnt + 1);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> st >> en;
  solve(st, 0);
  if(ans == INF) cout << -1;
  else cout << ans + 1;
}