#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    string a, b; cin >> a >> b;
    bool vis[a.size()] = {};
    int pos = a.find(b);
    int ans = 0;
    while (pos != -1) {
      for (int i = 0; i < b.size(); i++) {
        vis[pos + i] = 1;
      }
      ans++;
      pos = a.find(b, pos + b.size());
    }
    for (int i = 0; i < a.size(); i++) {
      ans += !vis[i];
    }
    cout << ans << '\n';
  }
}
