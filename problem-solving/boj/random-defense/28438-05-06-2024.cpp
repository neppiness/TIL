#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q; cin >> n >> m >> q;
  vector<int> rop(n + 1), cop(m + 1);

  while (q--) {
    int code, no, x;
    cin >> code >> no >> x;
    switch(code) {
      case 1:  rop[no] += x; break;
      default: cop[no] += x;
    }
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cout << rop[i] + cop[j] << " \n"[j == m];
}
