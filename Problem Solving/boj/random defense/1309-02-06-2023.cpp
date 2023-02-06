#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
const int MOD = 9'901;

int cache[MX + 2][3];

int solve(int i, int j) {
  if(i == 1) return 1;
  int &ret = cache[i][j];
  if(ret != -1) return ret;
  ret = 0;

  for(int p = 0; p < 3; p++) {
    if(p & j) continue;
    ret += solve(i - 1, p);
    if(ret >= MOD) ret -= MOD;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  int n; cin >> n;
  int ans = 0;
  for(int i = 0; i < 3; i++) {
    ans += solve(n, i);
    if(ans >= MOD) ans -= MOD;
  }
  cout << ans;
}