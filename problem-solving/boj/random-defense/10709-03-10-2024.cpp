#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

char b[102][102];
int ans[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];

  for (int i = 0; i < n; i++)
    fill(ans[i], ans[i] + m, INF);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        int cur = j - k;
        if (cur < 0) break;
        if (b[i][cur] != 'c') continue;
        ans[i][j] = min(ans[i][j], k);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ans[i][j] == INF) ans[i][j] = -1;
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}
