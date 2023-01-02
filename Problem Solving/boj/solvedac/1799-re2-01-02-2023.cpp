#include <bits/stdc++.h>
using namespace std;

int mx; // diagonal index array maximum size;
int cf; // correct factor

int n, ans;
vector<pair<int, int>> dg[19]; // dg[mi];
bool ps[19];

void solve(int lv, int cur) {
  for(int i = cur; i < mx; i++) {
    for(auto [x, y] : dg[i]) {
      if(ps[x + y]) continue;
      ps[x + y] = 1;
      ans = max(ans, lv);
      solve(lv + 1, cur + 1);
      ps[x + y] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cf = n - 1; mx = 2*n - 1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      bool bs; cin >> bs;
      if(bs) dg[i - j + cf].push_back({i, j});
    }
  
  solve(0, 0);
  cout << ans;
}