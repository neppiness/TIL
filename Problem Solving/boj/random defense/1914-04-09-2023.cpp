#include <bits/stdc++.h>
using namespace std;

int n; long long ans[102];
vector<pair<int, int>> seq;

void solve(int from, int to, int sz) {
  if(sz == 1) {
    seq.push_back({from, to});
    return;
  }
  int nxt = 3 - (from + to);
  solve(from, nxt, sz - 1);
  seq.push_back({from, to});
  solve(nxt, to, sz - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if(n <= 20) {
    cout << (1 << n) - 1 << '\n';
    solve(0, 2, n);
    for(auto [a, b] : seq)
      cout << a + 1 << ' ' << b + 1 << '\n';
    return 0;
  }

  if(n < 63) cout << ((long long)1 << n) - 1;
  else cout << ans[n];
}