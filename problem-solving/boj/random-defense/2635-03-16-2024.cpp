#include <bits/stdc++.h>
using namespace std;

vector<int> ans, a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    a.resize(0);
    a.push_back(n);
    a.push_back(i);
    int nxt = n - i;
    do {
      a.push_back(nxt);
      nxt = a[a.size() - 2] - a[a.size() - 1];
    } while (nxt >= 0);
    if (a.size() > ans.size()) {
      ans = vector<int>(a);
    }
  }
  cout << ans.size() << '\n';
  for (int x : ans) cout << x << ' ';
}
