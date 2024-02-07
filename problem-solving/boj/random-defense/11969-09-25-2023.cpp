#include <bits/stdc++.h>
using namespace std;

int acc_cnt[100'002][4];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    for (int j = 1; j <= 3; j++)
      acc_cnt[i][j] += acc_cnt[i - 1][j] + (x == j);
  }

  while (q--) {
    int a, b; cin >> a >> b;
    for (int j = 1; j <= 3; j++)
      cout << acc_cnt[b][j] - acc_cnt[a - 1][j] << ' ';
    cout << '\n';
  }
}
