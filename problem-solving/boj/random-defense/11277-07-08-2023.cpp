#include <bits/stdc++.h>
using namespace std;

int n, m;
bool comb[22];
pair<int, int> cl[102];

bool solve(int no_of_t) {
  if (no_of_t != 0) comb[n - no_of_t + 1] = 1;
  do {
    bool is_sat = 1;
    for (int i = 0; i < m; i++) {
      auto [u, v] = cl[i];
      int exp_u = (u > 0), exp_v = (v > 0);
      u = abs(u); v = abs(v);
      if ((comb[u] == exp_u) || (comb[v] == exp_v)) continue;
      is_sat = 0; break;
    }
    if (is_sat) return 1;
  } while(next_permutation(comb + 1, comb + n + 1));
  return 0;
}

bool solve() {
  for (int i = 0; i <= n; i++)
    if (solve(i)) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    cl[i] = {u, v};
  }
  cout << solve();
}