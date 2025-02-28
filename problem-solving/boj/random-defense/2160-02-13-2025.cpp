#include <bits/stdc++.h>
using namespace std;

char a[52][5][7];

int solve(int k2, int k1) {
  int cnt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 7; j++) {
      cnt += (a[k2][i][j] != a[k1][i][j]);
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int k = 1; k <= n; k++)
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 7; j++)
        cin >> a[k][i][j];

  pair<int, int> ans = {0, 0};
  int mn = 0x7f7f7f7f;
  for (int k1 = 1; k1 <= n; k1++) {
    for (int k2 = 1; k2 < k1; k2++) {
      int cnt = solve(k2, k1);     
      if (cnt < mn) {
        mn = cnt;
        ans = {k2, k1};
      }
    }
  }
  cout << ans.first << ' ' << ans.second;
}

