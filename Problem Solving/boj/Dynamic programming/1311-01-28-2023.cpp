#include <bits/stdc++.h>
using namespace std;

const int MX = (1 << 20) - 1;
const int INF = 0x7f7f7f7f;

int mx, n;
int cost[22][22], cache[MX + 2];

vector<bool> comb;

int solve(int picked, int cur) {
  if(!cur) return 0;
  int &ret = cache[cur];
  if(ret != INF) return ret;
  
  for(int i = 0; i < n; i++) {
    int x = (1 << i);
    if(!(cur & x)) continue;
    ret = min(ret, cost[picked][i] + solve(picked + 1, cur ^ x));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(cache + 1, cache + MX + 1, INF);

  cin >> n;

  for(int i = 0; i < n; i++)
    comb.push_back(0);

  mx = (1 << n) - 1;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> cost[i][j];

  solve(0, mx);
  cout << cache[mx] << '\n';
}