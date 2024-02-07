#include <bits/stdc++.h>
using namespace std;

vector<int> dot[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x, col; cin >> x >> col;
    dot[col].push_back(x);
  }

  for (int i = 1; i <= n; i++)
    sort(dot[i].begin(), dot[i].end());

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < dot[i].size(); j++) {
      if (dot[i].size() == 1) break;
      if (j == 0) {
        ans += dot[i][j + 1] - dot[i][j];
      } else if (j == dot[i].size() - 1) {
        ans += dot[i][j] - dot[i][j - 1];
      } else {
        int tmp = dot[i][j + 1] - dot[i][j];
        tmp = min(tmp, dot[i][j] - dot[i][j - 1]);
        ans += tmp;
      }
    }
  }
  cout << ans;
}
