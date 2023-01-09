#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000;

vector<int> mem, cost;
int n, req;
int cache[102][MX + 2]; // obtained memory value indexed by [app idx][tot cost]

void solve() {
  memset(cache, -1, sizeof(cache));
  cache[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= MX; j++) {
      if(cache[i - 1][j] == -1) continue;
      cache[i][j] = max(cache[i][j], cache[i - 1][j]);
      int m = mem[i - 1];
      int c = cost[i - 1];
      cache[i][j + c] = max(cache[i][j + c], cache[i - 1][j] + m);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> req;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    mem.push_back(x);
  }
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    cost.push_back(x);
  }
  solve();

  for(int co = 0; co <= MX; co++) {
    if(cache[n][co] < req) continue;
    cout << co;
    return 0;
  }
}