#include <bits/stdc++.h>
using namespace std;

int n, a[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool b[10] = {};

    for (int diff = -4; diff <= 4; diff++) {
      int x = a[i] + diff;
      auto it = find(a, a + n, x);
      if (it == a + n) continue;
      b[diff + 4] = 1;
    }

    for (int j = 0; j <= 4; j++) {
      int cnt = 0;
      for (int k = 0; k <= 4; k++)
        cnt += b[j + k];
      ans = max(ans, cnt);
    }
  }
  cout << 5 - ans;
}
