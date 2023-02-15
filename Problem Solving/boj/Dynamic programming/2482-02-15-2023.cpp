#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'003;
const int MX = 1'000 + 2;

int n, k, init;
int cache[MX][MX];

int solve(int cur, int x) {
  int &ret = cache[cur][x];
  if(ret != -1) return ret;
  if(x == k) {
    bool is_adj = (cur == n - 1) && (init == 0);
    return ret = !is_adj;
  }
  ret = 0;
  for(int i = cur + 2; i < n; i++) {
    ret += solve(i, x + 1);
    if(ret >= MOD) ret -= MOD;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n >> k;

  int ans = solve(0, 1);
  memset(cache, -1, sizeof(cache));
  for(init = 1; init < n; init++) {
    ans += solve(init, 1);
    if(ans >= MOD) ans -= MOD;
  }
  cout << ans;
}