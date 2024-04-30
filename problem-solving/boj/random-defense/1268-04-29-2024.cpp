#include <bits/stdc++.h>
using namespace std;

int st[1002][7];
int cnt[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 5; j++)
      cin >> st[i][j];

  int mx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == i) continue;
      bool was_in_same_class = 0;
      for (int k = 0; k < 5; k++) {
        was_in_same_class |= (st[i][k] == st[j][k]);
      }
      cnt[i] += was_in_same_class;
    }
    mx = max(mx, cnt[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (cnt[i] != mx) continue;
    cout << i;
    return 0;
  }
}
