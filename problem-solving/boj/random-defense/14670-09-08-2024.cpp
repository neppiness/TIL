#include <bits/stdc++.h>
using namespace std;

int sym_to_med[102];
int memo[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(sym_to_med, -1, sizeof(sym_to_med));

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int s, m; cin >> s >> m;
    sym_to_med[s] = m;
  }
  int t; cin >> t;
  while (t--) {
    cin >> n;
    bool is_cured = 1;
    for (int i = 0; i < n; i++) {
      int s; cin >> s;
      int med = sym_to_med[s];
      if (med == -1) {
        is_cured = 0;
      } else {
        memo[i] = med;
      }
    }
    if (is_cured) {
      for (int i = 0; i < n; i++)
        cout << memo[i] << ' ';
      cout << '\n';
    } else {
      cout << "YOU DIED\n";
    }
  }
}
