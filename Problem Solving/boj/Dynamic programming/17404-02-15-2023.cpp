#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000 + 2;
const int INF = 0x3f3f3f3f;

int n, ic; // initial color
int cost[MX][3], cache[MX][3];

int solve(int ci, int cc) {
  int &ret = cache[ci][cc];
  if(ret != -1) return ret;
  if(ci == n - 1) {
    if(cc == ic) return INF;
    else return cost[ci][cc];
  }

  ret = cost[ci][cc];
  int d = INF;
  for(int nc = 0; nc < 3; nc++) {
    if(nc == cc) continue;
    d = min(d, solve(ci + 1, nc));
  }
  return ret = ret + d;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < 3; j++)
      cin >> cost[i][j];

  int ans = INF;
  for(; ic < 3; ic++) {
    memset(cache, -1, sizeof(cache));
    ans = min(solve(0, ic), ans);
  }
  cout << ans;
}