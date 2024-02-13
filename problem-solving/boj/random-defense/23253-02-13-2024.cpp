#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  bool is_solved = 1;
  while (m--) {
    int k; cin >> k;
    int cur = n + 1;
    for (int i = 0; i < k; i++) {
      int nxt; cin >> nxt;
      if (cur < nxt) is_solved = 0;
      cur = nxt;
    }
  }
  string ans[] = {"No", "Yes"};
  cout << ans[is_solved];
}
