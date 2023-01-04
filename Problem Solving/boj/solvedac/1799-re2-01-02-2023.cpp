#include <bits/stdc++.h>
using namespace std;

int mx; // diagonal index array maximum size;
int cf; // correction factor

int n, ans[2];
vector<int> dg[19]; // dg[x - y + cf] = x + y
bool ps[19];

void solve(int nobs, int row, bool code) {
  ans[code] = max(ans[code], nobs);
  if(row >= mx) return;
  solve(nobs, row + 2, code);
  for(int k : dg[row]) {
    if(ps[k]) continue;
    ps[k] = 1;
    solve(nobs + 1, row + 2, code);
    ps[k] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cf = n - 1; mx = 2 * n - 1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      bool bs; cin >> bs;
      if(bs) dg[i - j + cf].push_back(i + j);
    }
  
  solve(0, 0, 0);
  solve(0, 1, 1);
  cout << ans[0] + ans[1];
}