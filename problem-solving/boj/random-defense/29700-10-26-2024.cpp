#include <bits/stdc++.h>
using namespace std;

bool board[1002][5002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (int j = 0; j < m; j++)
      board[i][j] = (s[j] == '1');
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - k + 1; j++) {
      bool is_able = 1;
      for (int p = 0; p < k; p++) {
        if (!board[i][j + p]) continue;
        is_able = 0;
        break;
      }
      ans += is_able;
    }
  }
  cout << ans;
}
